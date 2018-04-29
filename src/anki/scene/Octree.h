// Copyright (C) 2009-2018, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include <anki/scene/Common.h>
#include <anki/Math.h>
#include <anki/collision/Forward.h>
#include <anki/util/WeakArray.h>
#include <anki/util/Enum.h>
#include <anki/util/ObjectAllocator.h>
#include <anki/util/List.h>

namespace anki
{

// Forward
class OctreePlaceable;

/// @addtogroup scene
/// @{

/// Octree for visibility tests.
class Octree
{
	friend class OctreePlaceable;

public:
	Octree(SceneAllocator<U8> alloc)
		: m_alloc(alloc)
	{
	}

	~Octree();

	void init(const Vec3& sceneAabbMin, const Vec3& sceneAabbMax, U32 maxDepth);

	/// Place or re-place an element in the tree.
	/// @note It's thread-safe against place and remove methods.
	void place(const Aabb& volume, OctreePlaceable* placeable);

	/// Remove an element from the tree.
	/// @note It's thread-safe against place and remove methods.
	void remove(OctreePlaceable& placeable);

	/// Gather visible placeables.
	/// @note It's thread-safe against other gatherVisible calls.
	void gatherVisible(const Frustum& frustum, U32 testId, DynamicArrayAuto<OctreePlaceable*>& out)
	{
		gatherVisibleRecursive(frustum, testId, m_rootLeaf, out);
	}

private:
	/// List node.
	class PlaceableNode : public IntrusiveListEnabled<PlaceableNode>
	{
	public:
		OctreePlaceable* m_placeable = nullptr;

#if ANKI_ASSERTS_ENABLED
		~PlaceableNode()
		{
			m_placeable = nullptr;
		}
#endif
	};

	/// Octree leaf.
	/// @warning Keept its size as small as possible.
	class Leaf
	{
	public:
		IntrusiveList<PlaceableNode> m_placeables;
		Vec3 m_aabbMin;
		Vec3 m_aabbMax;
		Array<Leaf*, 8> m_children = {};

#if ANKI_ASSERTS_ENABLED
		~Leaf()
		{
			ANKI_ASSERT(m_placeables.isEmpty());
			m_children = {};
			m_aabbMin = m_aabbMax = Vec3(0.0f);
		}
#endif

		Bool hasChildren() const
		{
			return m_children[0] != nullptr || m_children[1] != nullptr || m_children[2] != nullptr
				   || m_children[3] != nullptr || m_children[4] != nullptr || m_children[5] != nullptr
				   || m_children[6] != nullptr || m_children[7] != nullptr;
		}
	};

	/// Used so that OctreePlaceable knows which leafs it belongs to.
	class LeafNode : public IntrusiveListEnabled<LeafNode>
	{
	public:
		Leaf* m_leaf = nullptr;

#if ANKI_ASSERTS_ENABLED
		~LeafNode()
		{
			m_leaf = nullptr;
		}
#endif
	};

	/// P: Stands for positive and N: Negative
	enum class LeafMask : U8
	{
		PX_PY_PZ = 1 << 0,
		PX_PY_NZ = 1 << 1,
		PX_NY_PZ = 1 << 2,
		PX_NY_NZ = 1 << 3,
		NX_PY_PZ = 1 << 4,
		NX_PY_NZ = 1 << 5,
		NX_NY_PZ = 1 << 6,
		NX_NY_NZ = 1 << 7,

		NONE = 0,
		ALL = PX_PY_PZ | PX_PY_NZ | PX_NY_PZ | PX_NY_NZ | NX_PY_PZ | NX_PY_NZ | NX_NY_PZ | NX_NY_NZ,
		RIGHT = PX_PY_PZ | PX_PY_NZ | PX_NY_PZ | PX_NY_NZ,
		LEFT = NX_PY_PZ | NX_PY_NZ | NX_NY_PZ | NX_NY_NZ,
		TOP = PX_PY_PZ | PX_PY_NZ | NX_PY_PZ | NX_PY_NZ,
		BOTTOM = PX_NY_PZ | PX_NY_NZ | NX_NY_PZ | NX_NY_NZ,
		FRONT = PX_PY_PZ | PX_NY_PZ | NX_PY_PZ | NX_NY_PZ,
		BACK = PX_PY_NZ | PX_NY_NZ | NX_PY_NZ | NX_NY_NZ,
	};
	ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(LeafMask, friend)

	SceneAllocator<U8> m_alloc;
	U32 m_maxDepth = 0;
	Vec3 m_sceneAabbMin = Vec3(0.0f);
	Vec3 m_sceneAabbMax = Vec3(0.0f);
	Mutex m_globalMtx;

	ObjectAllocatorSameType<Leaf, 256> m_leafAlloc;
	ObjectAllocatorSameType<LeafNode, 128> m_leafNodeAlloc;
	ObjectAllocatorSameType<PlaceableNode, 256> m_placeableNodeAlloc;

	Leaf* m_rootLeaf = nullptr;
	U32 m_placeableCount = 0;

	Leaf* newLeaf()
	{
		return m_leafAlloc.newInstance(m_alloc);
	}

	void releaseLeaf(Leaf* leaf)
	{
		m_leafAlloc.deleteInstance(m_alloc, leaf);
	}

	PlaceableNode* newPlaceableNode(OctreePlaceable* placeable)
	{
		ANKI_ASSERT(placeable);
		PlaceableNode* out = m_placeableNodeAlloc.newInstance(m_alloc);
		out->m_placeable = placeable;
		return out;
	}

	void releasePlaceableNode(PlaceableNode* placeable)
	{
		m_placeableNodeAlloc.deleteInstance(m_alloc, placeable);
	}

	LeafNode* newLeafNode(Leaf* leaf)
	{
		ANKI_ASSERT(leaf);
		LeafNode* out = m_leafNodeAlloc.newInstance(m_alloc);
		out->m_leaf = leaf;
		return out;
	}

	void releaseLeafNode(LeafNode* node)
	{
		m_leafNodeAlloc.deleteInstance(m_alloc, node);
	}

	void placeRecursive(const Aabb& volume, OctreePlaceable* placeable, Leaf* parent, U32 depth);

	static void computeChildAabb(LeafMask child,
		const Vec3& parentAabbMin,
		const Vec3& parentAabbMax,
		const Vec3& parentAabbCenter,
		Vec3& childAabbMin,
		Vec3& childAabbMax);

	/// Remove a placeable from the tree.
	void removeInternal(OctreePlaceable& placeable);

	static void gatherVisibleRecursive(
		const Frustum& frustum, U32 testId, Leaf* leaf, DynamicArrayAuto<OctreePlaceable*>& out);

	/// Remove a leaf.
	void cleanupRecursive(Leaf* leaf, Bool& canDeleteLeafAfterThat);

	/// Cleanup the tree.
	void cleanupInternal();
};

/// An entity that can be placed in octrees.
class OctreePlaceable
{
	friend class Octree;

public:
	void reset()
	{
		m_visitedMask.set(0);
	}

private:
	Atomic<U64> m_visitedMask = {0u};
	IntrusiveList<Octree::LeafNode> m_leafs; ///< A list of leafs this placeable belongs.

	/// Check if already visited.
	/// @note It's thread-safe.
	Bool alreadyVisited(U32 testId)
	{
		const U64 testMask = U64(1u) << U64(testId);
		const U64 prev = m_visitedMask.fetchOr(testMask);
		return !!(testMask & prev);
	}
};
/// @}

} // end namespace anki
