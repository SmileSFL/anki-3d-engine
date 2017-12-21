// Copyright (C) 2009-2017, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#include <anki/gr/vulkan/TextureViewImpl.h>
#include <anki/gr/vulkan/TextureImpl.h>

namespace anki
{

TextureViewImpl::~TextureViewImpl()
{
}

Error TextureViewImpl::init(const TextureViewInitInfo& inf)
{
	ANKI_ASSERT(inf.isValid());

	// Store some stuff
	m_aspect = inf.m_depthStencilAspect;
	m_baseMip = inf.m_baseMipmap;
	m_mipCount = inf.m_mipmapCount;
	m_baseLayer = inf.m_baseLayer;
	m_layerCount = inf.m_layerCount;
	m_baseFace = inf.m_baseFace;
	m_faceCount = inf.m_faceCount;
	// TODO Set m_texType

	m_tex = inf.m_texture;

	const TextureImpl& tex = static_cast<const TextureImpl&>(*m_tex);

	// Compute the VK range
	VkImageSubresourceRange range;
	range.aspectMask = tex.convertAspect(m_aspect);
	range.baseMipLevel = m_baseMip;
	range.levelCount = m_mipCount;

	const TextureType type = tex.getTextureType();
	const U32 faceCount = type == TextureType::CUBE_ARRAY || type == TextureType::CUBE;
	range.baseArrayLayer = m_baseLayer * faceCount + m_baseFace;
	range.layerCount = m_layerCount * m_faceCount;

	// Ask the texture for a view
	m_handle = tex.getOrCreateView(range);

	return Error::NONE;
}

} // end namespace anki
