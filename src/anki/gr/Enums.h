// Copyright (C) 2009-2018, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include <anki/util/StdTypes.h>
#include <anki/util/Enum.h>
#include <anki/util/Array.h>

namespace anki
{

/// @addtogroup graphics
/// @{
enum ColorBit : U8
{
	NONE = 0,
	RED = 1 << 0,
	GREEN = 1 << 1,
	BLUE = 1 << 2,
	ALPHA = 1 << 3,
	ALL = RED | GREEN | BLUE | ALPHA
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(ColorBit, inline)

enum PrimitiveTopology : U8
{
	POINTS,
	LINES,
	LINE_STIP,
	TRIANGLES,
	TRIANGLE_STRIP,
	PATCHES
};

enum class FillMode : U8
{
	POINTS,
	WIREFRAME,
	SOLID,
	COUNT
};

enum class FaceSelectionBit : U8
{
	FRONT = 1 << 0,
	BACK = 1 << 1,
	FRONT_AND_BACK = FRONT | BACK
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(FaceSelectionBit, inline)

enum class CompareOperation : U8
{
	ALWAYS,
	LESS,
	EQUAL,
	LESS_EQUAL,
	GREATER,
	GREATER_EQUAL,
	NOT_EQUAL,
	NEVER,
	COUNT
};

enum class StencilOperation : U8
{
	KEEP,
	ZERO,
	REPLACE,
	INCREMENT_AND_CLAMP,
	DECREMENT_AND_CLAMP,
	INVERT,
	INCREMENT_AND_WRAP,
	DECREMENT_AND_WRAP,
	COUNT
};

enum class BlendFactor : U8
{
	ZERO,
	ONE,
	SRC_COLOR,
	ONE_MINUS_SRC_COLOR,
	DST_COLOR,
	ONE_MINUS_DST_COLOR,
	SRC_ALPHA,
	ONE_MINUS_SRC_ALPHA,
	DST_ALPHA,
	ONE_MINUS_DST_ALPHA,
	CONSTANT_COLOR,
	ONE_MINUS_CONSTANT_COLOR,
	CONSTANT_ALPHA,
	ONE_MINUS_CONSTANT_ALPHA,
	SRC_ALPHA_SATURATE,
	SRC1_COLOR,
	ONE_MINUS_SRC1_COLOR,
	SRC1_ALPHA,
	ONE_MINUS_SRC1_ALPHA,
	COUNT
};

enum class BlendOperation : U8
{
	ADD,
	SUBTRACT,
	REVERSE_SUBTRACT,
	MIN,
	MAX,
	COUNT
};

enum class VertexStepRate : U8
{
	VERTEX,
	INSTANCE,
	DRAW,
	COUNT
};

/// A way to distinguish the aspect of a depth stencil texture.
enum class DepthStencilAspectBit : U8
{
	NONE = 0,
	DEPTH = 1 << 0,
	STENCIL = 1 << 1,
	DEPTH_STENCIL = DEPTH | STENCIL
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(DepthStencilAspectBit, inline)

/// Pixel or vertex format.
/// WARNING: Keep it the same as vulkan (one conversion less).
enum class Format : U32
{
	NONE = 0,
	R4G4_UNORM_PACK8 = 1,
	R4G4B4A4_UNORM_PACK16 = 2,
	B4G4R4A4_UNORM_PACK16 = 3,
	R5G6B5_UNORM_PACK16 = 4,
	B5G6R5_UNORM_PACK16 = 5,
	R5G5B5A1_UNORM_PACK16 = 6,
	B5G5R5A1_UNORM_PACK16 = 7,
	A1R5G5B5_UNORM_PACK16 = 8,
	R8_UNORM = 9,
	R8_SNORM = 10,
	R8_USCALED = 11,
	R8_SSCALED = 12,
	R8_UINT = 13,
	R8_SINT = 14,
	R8_SRGB = 15,
	R8G8_UNORM = 16,
	R8G8_SNORM = 17,
	R8G8_USCALED = 18,
	R8G8_SSCALED = 19,
	R8G8_UINT = 20,
	R8G8_SINT = 21,
	R8G8_SRGB = 22,
	R8G8B8_UNORM = 23,
	R8G8B8_SNORM = 24,
	R8G8B8_USCALED = 25,
	R8G8B8_SSCALED = 26,
	R8G8B8_UINT = 27,
	R8G8B8_SINT = 28,
	R8G8B8_SRGB = 29,
	B8G8R8_UNORM = 30,
	B8G8R8_SNORM = 31,
	B8G8R8_USCALED = 32,
	B8G8R8_SSCALED = 33,
	B8G8R8_UINT = 34,
	B8G8R8_SINT = 35,
	B8G8R8_SRGB = 36,
	R8G8B8A8_UNORM = 37,
	R8G8B8A8_SNORM = 38,
	R8G8B8A8_USCALED = 39,
	R8G8B8A8_SSCALED = 40,
	R8G8B8A8_UINT = 41,
	R8G8B8A8_SINT = 42,
	R8G8B8A8_SRGB = 43,
	B8G8R8A8_UNORM = 44,
	B8G8R8A8_SNORM = 45,
	B8G8R8A8_USCALED = 46,
	B8G8R8A8_SSCALED = 47,
	B8G8R8A8_UINT = 48,
	B8G8R8A8_SINT = 49,
	B8G8R8A8_SRGB = 50,
	A8B8G8R8_UNORM_PACK32 = 51,
	A8B8G8R8_SNORM_PACK32 = 52,
	A8B8G8R8_USCALED_PACK32 = 53,
	A8B8G8R8_SSCALED_PACK32 = 54,
	A8B8G8R8_UINT_PACK32 = 55,
	A8B8G8R8_SINT_PACK32 = 56,
	A8B8G8R8_SRGB_PACK32 = 57,
	A2R10G10B10_UNORM_PACK32 = 58,
	A2R10G10B10_SNORM_PACK32 = 59,
	A2R10G10B10_USCALED_PACK32 = 60,
	A2R10G10B10_SSCALED_PACK32 = 61,
	A2R10G10B10_UINT_PACK32 = 62,
	A2R10G10B10_SINT_PACK32 = 63,
	A2B10G10R10_UNORM_PACK32 = 64,
	A2B10G10R10_SNORM_PACK32 = 65,
	A2B10G10R10_USCALED_PACK32 = 66,
	A2B10G10R10_SSCALED_PACK32 = 67,
	A2B10G10R10_UINT_PACK32 = 68,
	A2B10G10R10_SINT_PACK32 = 69,
	R16_UNORM = 70,
	R16_SNORM = 71,
	R16_USCALED = 72,
	R16_SSCALED = 73,
	R16_UINT = 74,
	R16_SINT = 75,
	R16_SFLOAT = 76,
	R16G16_UNORM = 77,
	R16G16_SNORM = 78,
	R16G16_USCALED = 79,
	R16G16_SSCALED = 80,
	R16G16_UINT = 81,
	R16G16_SINT = 82,
	R16G16_SFLOAT = 83,
	R16G16B16_UNORM = 84,
	R16G16B16_SNORM = 85,
	R16G16B16_USCALED = 86,
	R16G16B16_SSCALED = 87,
	R16G16B16_UINT = 88,
	R16G16B16_SINT = 89,
	R16G16B16_SFLOAT = 90,
	R16G16B16A16_UNORM = 91,
	R16G16B16A16_SNORM = 92,
	R16G16B16A16_USCALED = 93,
	R16G16B16A16_SSCALED = 94,
	R16G16B16A16_UINT = 95,
	R16G16B16A16_SINT = 96,
	R16G16B16A16_SFLOAT = 97,
	R32_UINT = 98,
	R32_SINT = 99,
	R32_SFLOAT = 100,
	R32G32_UINT = 101,
	R32G32_SINT = 102,
	R32G32_SFLOAT = 103,
	R32G32B32_UINT = 104,
	R32G32B32_SINT = 105,
	R32G32B32_SFLOAT = 106,
	R32G32B32A32_UINT = 107,
	R32G32B32A32_SINT = 108,
	R32G32B32A32_SFLOAT = 109,
	R64_UINT = 110,
	R64_SINT = 111,
	R64_SFLOAT = 112,
	R64G64_UINT = 113,
	R64G64_SINT = 114,
	R64G64_SFLOAT = 115,
	R64G64B64_UINT = 116,
	R64G64B64_SINT = 117,
	R64G64B64_SFLOAT = 118,
	R64G64B64A64_UINT = 119,
	R64G64B64A64_SINT = 120,
	R64G64B64A64_SFLOAT = 121,
	B10G11R11_UFLOAT_PACK32 = 122,
	E5B9G9R9_UFLOAT_PACK32 = 123,
	D16_UNORM = 124,
	X8_D24_UNORM_PACK32 = 125,
	D32_SFLOAT = 126,
	S8_UINT = 127,
	D16_UNORM_S8_UINT = 128,
	D24_UNORM_S8_UINT = 129,
	D32_SFLOAT_S8_UINT = 130,
	BC1_RGB_UNORM_BLOCK = 131,
	BC1_RGB_SRGB_BLOCK = 132,
	BC1_RGBA_UNORM_BLOCK = 133,
	BC1_RGBA_SRGB_BLOCK = 134,
	BC2_UNORM_BLOCK = 135,
	BC2_SRGB_BLOCK = 136,
	BC3_UNORM_BLOCK = 137,
	BC3_SRGB_BLOCK = 138,
	BC4_UNORM_BLOCK = 139,
	BC4_SNORM_BLOCK = 140,
	BC5_UNORM_BLOCK = 141,
	BC5_SNORM_BLOCK = 142,
	BC6H_UFLOAT_BLOCK = 143,
	BC6H_SFLOAT_BLOCK = 144,
	BC7_UNORM_BLOCK = 145,
	BC7_SRGB_BLOCK = 146,
	ETC2_R8G8B8_UNORM_BLOCK = 147,
	ETC2_R8G8B8_SRGB_BLOCK = 148,
	ETC2_R8G8B8A1_UNORM_BLOCK = 149,
	ETC2_R8G8B8A1_SRGB_BLOCK = 150,
	ETC2_R8G8B8A8_UNORM_BLOCK = 151,
	ETC2_R8G8B8A8_SRGB_BLOCK = 152,
	EAC_R11_UNORM_BLOCK = 153,
	EAC_R11_SNORM_BLOCK = 154,
	EAC_R11G11_UNORM_BLOCK = 155,
	EAC_R11G11_SNORM_BLOCK = 156,
	ASTC_4x4_UNORM_BLOCK = 157,
	ASTC_4x4_SRGB_BLOCK = 158,
	ASTC_5x4_UNORM_BLOCK = 159,
	ASTC_5x4_SRGB_BLOCK = 160,
	ASTC_5x5_UNORM_BLOCK = 161,
	ASTC_5x5_SRGB_BLOCK = 162,
	ASTC_6x5_UNORM_BLOCK = 163,
	ASTC_6x5_SRGB_BLOCK = 164,
	ASTC_6x6_UNORM_BLOCK = 165,
	ASTC_6x6_SRGB_BLOCK = 166,
	ASTC_8x5_UNORM_BLOCK = 167,
	ASTC_8x5_SRGB_BLOCK = 168,
	ASTC_8x6_UNORM_BLOCK = 169,
	ASTC_8x6_SRGB_BLOCK = 170,
	ASTC_8x8_UNORM_BLOCK = 171,
	ASTC_8x8_SRGB_BLOCK = 172,
	ASTC_10x5_UNORM_BLOCK = 173,
	ASTC_10x5_SRGB_BLOCK = 174,
	ASTC_10x6_UNORM_BLOCK = 175,
	ASTC_10x6_SRGB_BLOCK = 176,
	ASTC_10x8_UNORM_BLOCK = 177,
	ASTC_10x8_SRGB_BLOCK = 178,
	ASTC_10x10_UNORM_BLOCK = 179,
	ASTC_10x10_SRGB_BLOCK = 180,
	ASTC_12x10_UNORM_BLOCK = 181,
	ASTC_12x10_SRGB_BLOCK = 182,
	ASTC_12x12_UNORM_BLOCK = 183,
	ASTC_12x12_SRGB_BLOCK = 184,
	PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
	PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
	PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
	PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
	PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
	PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
	PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
	PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007,
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(Format, inline)

inline Bool formatIsDepthStencil(const Format fmt)
{
	return fmt == Format::D16_UNORM || fmt == Format::D16_UNORM_S8_UINT || fmt == Format::D24_UNORM_S8_UINT
		   || fmt == Format::D32_SFLOAT || fmt == Format::D32_SFLOAT_S8_UINT || fmt == Format::S8_UINT;
}

inline Bool formatIsDepth(const Format fmt)
{
	return fmt == Format::D16_UNORM || fmt == Format::D16_UNORM_S8_UINT || fmt == Format::D24_UNORM_S8_UINT
		   || fmt == Format::D32_SFLOAT || fmt == Format::D32_SFLOAT_S8_UINT;
}

inline Bool formatIsStencil(const Format fmt)
{
	return fmt == Format::D16_UNORM_S8_UINT || fmt == Format::D24_UNORM_S8_UINT || fmt == Format::D32_SFLOAT_S8_UINT
		   || fmt == Format::S8_UINT;
}

inline Bool formatIsCompressed(const Format fmt)
{
	return (fmt >= Format::BC1_RGB_UNORM_BLOCK && fmt <= Format::ASTC_12x12_SRGB_BLOCK)
		   || (fmt >= Format::PVRTC1_2BPP_UNORM_BLOCK_IMG && fmt <= Format::PVRTC2_4BPP_SRGB_BLOCK_IMG);
}

inline DepthStencilAspectBit computeFormatAspect(const Format fmt)
{
	DepthStencilAspectBit out = formatIsDepth(fmt) ? DepthStencilAspectBit::DEPTH : DepthStencilAspectBit::NONE;
	out |= formatIsStencil(fmt) ? DepthStencilAspectBit::STENCIL : DepthStencilAspectBit::NONE;
	return out;
}

/// Texture type.
enum class TextureType : U8
{
	_1D,
	_2D,
	_3D,
	_2D_ARRAY,
	CUBE,
	CUBE_ARRAY,
	COUNT
};

inline Bool textureTypeIsCube(const TextureType t)
{
	return t == TextureType::CUBE || t == TextureType::CUBE_ARRAY;
}

/// Texture usage hints. They are very important.
enum class TextureUsageBit : U16
{
	NONE = 0,

	SAMPLED_VERTEX = 1 << 0,
	SAMPLED_TESSELLATION_CONTROL = 1 << 1,
	SAMPLED_TESSELLATION_EVALUATION = 1 << 2,
	SAMPLED_GEOMETRY = 1 << 3,
	SAMPLED_FRAGMENT = 1 << 4,
	SAMPLED_COMPUTE = 1 << 5,
	SAMPLED_ALL_GRAPHICS = SAMPLED_VERTEX | SAMPLED_TESSELLATION_CONTROL | SAMPLED_TESSELLATION_EVALUATION
						   | SAMPLED_GEOMETRY | SAMPLED_FRAGMENT,
	SAMPLED_ALL = SAMPLED_ALL_GRAPHICS | SAMPLED_COMPUTE,

	IMAGE_COMPUTE_READ = 1 << 6,
	IMAGE_COMPUTE_WRITE = 1 << 7,
	IMAGE_COMPUTE_READ_WRITE = IMAGE_COMPUTE_READ | IMAGE_COMPUTE_WRITE,
	IMAGE_ALL = IMAGE_COMPUTE_READ_WRITE,

	FRAMEBUFFER_ATTACHMENT_READ = 1 << 8,
	FRAMEBUFFER_ATTACHMENT_WRITE = 1 << 9,
	FRAMEBUFFER_ATTACHMENT_READ_WRITE = FRAMEBUFFER_ATTACHMENT_READ | FRAMEBUFFER_ATTACHMENT_WRITE,

	TRANSFER_DESTINATION = 1 << 10,
	TRANSFER_ALL = TRANSFER_DESTINATION,

	// Misc
	GENERATE_MIPMAPS = 1 << 11,
	CLEAR = 1 << 12, ///< Will be used in CommandBuffer::clearTextureView.
	PRESENT = 1 << 13,

	// Derived
	ALL_COMPUTE = SAMPLED_COMPUTE | IMAGE_COMPUTE_READ_WRITE,
	ALL_GRAPHICS = SAMPLED_ALL_GRAPHICS | FRAMEBUFFER_ATTACHMENT_READ_WRITE,
	ALL_READ = SAMPLED_ALL | IMAGE_COMPUTE_READ | FRAMEBUFFER_ATTACHMENT_READ | PRESENT | GENERATE_MIPMAPS,
	ALL_WRITE =
		IMAGE_COMPUTE_WRITE | FRAMEBUFFER_ATTACHMENT_WRITE | TRANSFER_DESTINATION | GENERATE_MIPMAPS | CLEAR | PRESENT,
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(TextureUsageBit, inline)

enum class SamplingFilter : U8
{
	NEAREST,
	LINEAR,
	BASE ///< Only for mipmaps
};

enum class ShaderType : U8
{
	VERTEX,
	TESSELLATION_CONTROL,
	TESSELLATION_EVALUATION,
	GEOMETRY,
	FRAGMENT,
	COMPUTE,

	COUNT,
	FIRST = VERTEX,
	LAST = COUNT - 1,
	FIRST_GRAPHICS = VERTEX,
	LAST_GRAPHICS = FRAGMENT,
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(ShaderType, inline)

enum class ShaderTypeBit : U8
{
	NONE = 0,
	VERTEX = 1 << 0,
	TESSELLATION_CONTROL = 1 << 1,
	TESSELLATION_EVALUATION = 1 << 2,
	GEOMETRY = 1 << 3,
	FRAGMENT = 1 << 4,
	COMPUTE = 1 << 5
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(ShaderTypeBit, inline)

enum class ShaderVariableDataType : U8
{
	NONE,
	INT,
	UINT,
	FLOAT,
	IVEC2,
	UVEC2,
	VEC2,
	IVEC3,
	UVEC3,
	VEC3,
	IVEC4,
	UVEC4,
	VEC4,
	MAT3,
	MAT4,
	SAMPLER_2D,
	SAMPLER_3D,
	SAMPLER_2D_ARRAY,
	SAMPLER_CUBE,

	NUMERICS_FIRST = INT,
	NUMERICS_LAST = MAT4,

	MATRIX_FIRST = MAT3,
	MATRIX_LAST = MAT4,

	SAMPLERS_FIRST = SAMPLER_2D,
	SAMPLERS_LAST = SAMPLER_CUBE
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(ShaderVariableDataType, inline)

/// Occlusion query result bit.
enum class OcclusionQueryResultBit : U8
{
	NOT_AVAILABLE = 1 << 0,
	VISIBLE = 1 << 1,
	NOT_VISIBLE = 1 << 2
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(OcclusionQueryResultBit, inline)

/// Occlusion query result.
enum class OcclusionQueryResult : U8
{
	NOT_AVAILABLE,
	VISIBLE,
	NOT_VISIBLE
};

/// Attachment load operation.
enum class AttachmentLoadOperation : U8
{
	LOAD,
	CLEAR,
	DONT_CARE
};

/// Attachment store operation.
enum class AttachmentStoreOperation : U8
{
	STORE,
	DONT_CARE
};

/// Buffer usage modes.
enum class BufferUsageBit : U64
{
	NONE = 0,

	UNIFORM_VERTEX = 1 << 0,
	UNIFORM_TESSELLATION_EVALUATION = 1 << 1,
	UNIFORM_TESSELLATION_CONTROL = 1 << 2,
	UNIFORM_GEOMETRY = 1 << 3,
	UNIFORM_FRAGMENT = 1 << 4,
	UNIFORM_COMPUTE = 1 << 5,
	UNIFORM_ALL_GRAPHICS = UNIFORM_VERTEX | UNIFORM_TESSELLATION_EVALUATION | UNIFORM_TESSELLATION_CONTROL
						   | UNIFORM_GEOMETRY | UNIFORM_FRAGMENT,
	UNIFORM_ALL = UNIFORM_ALL_GRAPHICS | UNIFORM_COMPUTE,

	STORAGE_VERTEX_READ = 1 << 6,
	STORAGE_VERTEX_WRITE = 1 << 7,
	STORAGE_VERTEX_READ_WRITE = STORAGE_VERTEX_READ | STORAGE_VERTEX_WRITE,
	STORAGE_TESSELLATION_EVALUATION_READ = 1 << 8,
	STORAGE_TESSELLATION_EVALUATION_WRITE = 1 << 9,
	STORAGE_TESSELLATION_EVALUATION_READ_WRITE =
		STORAGE_TESSELLATION_EVALUATION_READ | STORAGE_TESSELLATION_EVALUATION_WRITE,
	STORAGE_TESSELLATION_CONTROL_READ = 1 << 10,
	STORAGE_TESSELLATION_CONTROL_WRITE = 1 << 11,
	STORAGE_TESSELLATION_CONTROL_READ_WRITE = STORAGE_TESSELLATION_CONTROL_READ | STORAGE_TESSELLATION_CONTROL_WRITE,
	STORAGE_GEOMETRY_READ = 1 << 12,
	STORAGE_GEOMETRY_WRITE = 1 << 13,
	STORAGE_GEOMETRY_READ_WRITE = STORAGE_GEOMETRY_READ | STORAGE_GEOMETRY_WRITE,
	STORAGE_FRAGMENT_READ = 1 << 14,
	STORAGE_FRAGMENT_WRITE = 1 << 15,
	STORAGE_FRAGMENT_READ_WRITE = STORAGE_FRAGMENT_READ | STORAGE_FRAGMENT_WRITE,
	STORAGE_COMPUTE_READ = 1 << 16,
	STORAGE_COMPUTE_WRITE = 1 << 17,
	STORAGE_COMPUTE_READ_WRITE = STORAGE_COMPUTE_READ | STORAGE_COMPUTE_WRITE,
	STORAGE_ALL_GRAPHICS = STORAGE_VERTEX_READ_WRITE | STORAGE_TESSELLATION_EVALUATION_READ_WRITE
						   | STORAGE_TESSELLATION_CONTROL_READ_WRITE | STORAGE_GEOMETRY_READ_WRITE
						   | STORAGE_FRAGMENT_READ_WRITE,
	STORAGE_ALL = STORAGE_ALL_GRAPHICS | STORAGE_COMPUTE_READ_WRITE,
	STORAGE_ALL_READ = STORAGE_VERTEX_READ | STORAGE_TESSELLATION_EVALUATION_READ | STORAGE_TESSELLATION_CONTROL_READ
					   | STORAGE_GEOMETRY_READ | STORAGE_FRAGMENT_READ | STORAGE_COMPUTE_READ,
	STORAGE_ALL_WRITE = STORAGE_VERTEX_WRITE | STORAGE_TESSELLATION_EVALUATION_WRITE
						| STORAGE_TESSELLATION_CONTROL_WRITE | STORAGE_GEOMETRY_WRITE | STORAGE_FRAGMENT_WRITE
						| STORAGE_COMPUTE_WRITE,

	TEXTURE_VERTEX = 1 << 18,
	TEXTURE_TESSELLATION_EVALUATION = 1 << 19,
	TEXTURE_TESSELLATION_CONTROL = 1 << 20,
	TEXTURE_GEOMETRY = 1 << 21,
	TEXTURE_FRAGMENT = 1 << 22,
	TEXTURE_COMPUTE = 1 << 23,
	TEXTURE_ALL_GRAPHICS = TEXTURE_VERTEX | TEXTURE_TESSELLATION_EVALUATION | TEXTURE_TESSELLATION_CONTROL
						   | TEXTURE_GEOMETRY | TEXTURE_FRAGMENT,
	TEXTURE_ALL = TEXTURE_ALL_GRAPHICS | TEXTURE_COMPUTE,

	INDEX = 1 << 24,
	VERTEX = 1 << 25,
	INDIRECT = 1 << 26,

	FILL = 1 << 27,
	BUFFER_UPLOAD_SOURCE = 1 << 28,
	BUFFER_UPLOAD_DESTINATION = 1 << 29, ///< Destination of buffer upload.
	TEXTURE_UPLOAD_SOURCE = 1 << 30, ///< Source for texture upload.
	QUERY_RESULT = 1u << 31u, ///< Destination to store query results.
	TRANSFER_ALL_READ = BUFFER_UPLOAD_SOURCE | TEXTURE_UPLOAD_SOURCE,
	TRANSFER_ALL_WRITE = FILL | BUFFER_UPLOAD_DESTINATION | QUERY_RESULT,
	TRANSFER_ALL = TRANSFER_ALL_READ | TRANSFER_ALL_WRITE,

	// Derived
	ALL_GRAPHICS = UNIFORM_ALL_GRAPHICS | STORAGE_ALL_GRAPHICS | TEXTURE_ALL_GRAPHICS | INDEX | VERTEX | INDIRECT,
	ALL_COMPUTE = UNIFORM_COMPUTE | STORAGE_COMPUTE_READ_WRITE | TEXTURE_COMPUTE | INDIRECT,
	ALL_READ = UNIFORM_ALL | STORAGE_ALL_READ | TEXTURE_ALL | INDEX | VERTEX | INDIRECT | TRANSFER_ALL_READ,
	ALL_WRITE = STORAGE_ALL_WRITE | TRANSFER_ALL_WRITE,
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(BufferUsageBit, inline)

/// Buffer access when mapped.
enum class BufferMapAccessBit : U8
{
	NONE = 0,
	READ = 1 << 0,
	WRITE = 1 << 1
};
ANKI_ENUM_ALLOW_NUMERIC_OPERATIONS(BufferMapAccessBit, inline)

/// Index buffer's index type.
enum class IndexType : U8
{
	U16,
	U32,
	COUNT
};

/// Rasterization order.
enum class RasterizationOrder : U8
{
	ORDERED,
	RELAXED,
	COUNT
};
/// @}

} // end namespace anki
