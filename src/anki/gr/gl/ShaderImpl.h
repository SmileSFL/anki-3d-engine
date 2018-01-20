// Copyright (C) 2009-2018, Panagiotis Christopoulos Charitos and contributors.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include <anki/gr/Shader.h>
#include <anki/gr/gl/GlObject.h>

namespace anki
{

// Forward
class CString;

/// @addtogroup opengl
/// @{

/// Shader program implementation.
class ShaderImpl final : public Shader, public GlObject
{
public:
	GLenum m_glType = 0;

	ShaderImpl(GrManager* manager)
		: Shader(manager)
	{
	}

	~ShaderImpl();

	void preInit(const ShaderInitInfo& init)
	{
		m_shaderType = init.m_shaderType;
	}

	ANKI_USE_RESULT Error init(const CString& source);
};
/// @}

} // end namespace anki
