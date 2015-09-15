// Copyright (C) 2009-2015, Panagiotis Christopoulos Charitos.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

// Contains common structures for IS

#pragma anki include "shaders/Common.glsl"

// Common uniforms between lights
layout(std140, row_major, binding = 0) readonly buffer _s0
{
	vec4 u_projectionParams;
	vec4 u_sceneAmbientColor;
	vec4 u_groundLightDir;
	vec4 u_clustererParams;
	mat4 u_viewMat;
};
