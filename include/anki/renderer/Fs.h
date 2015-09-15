// Copyright (C) 2009-2015, Panagiotis Christopoulos Charitos.
// All rights reserved.
// Code licensed under the BSD License.
// http://www.anki3d.org/LICENSE

#pragma once

#include "anki/renderer/RenderingPass.h"

namespace anki {

/// @addtogroup renderer
/// @{

/// Forward rendering stage. The objects that blend must be handled differently
class Fs: public RenderingPass
{
anki_internal:
	Fs(Renderer* r)
		: RenderingPass(r)
	{}

	~Fs();

	ANKI_USE_RESULT Error init(const ConfigSet& initializer);
	ANKI_USE_RESULT Error run(CommandBufferPtr& cmdb);

private:
	FramebufferPtr m_fb;

	Array<ResourceGroupPtr, MAX_FRAMES_IN_FLIGHT> m_globalResources;
};
/// @}

} // end namespace anki

