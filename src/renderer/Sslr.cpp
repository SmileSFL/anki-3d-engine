#include "anki/renderer/Sslr.h"
#include "anki/renderer/Renderer.h"
#include <sstream>

namespace anki {

//==============================================================================
void Sslr::init(const RendererInitializer& initializer)
{
	m_enabled = initializer.get("pps.sslr.enabled");

	if(!m_enabled)
	{
		return;
	}

	// Size
	const F32 quality = initializer.get("pps.sslr.renderingQuality");

	m_width = quality * (F32)m_r->getWidth();
	alignRoundUp(16, m_width);
	m_height = quality * (F32)m_r->getHeight();
	alignRoundUp(16, m_height);

	// Programs
	std::stringstream pps;

	m_reflectionFrag.load(ProgramResource::createSrcCodeToCache(
		"shaders/PpsSslr.frag.glsl", pps.str().c_str(), "r_").c_str());

	m_reflectionPpline = m_r->createDrawQuadProgramPipeline(
		m_reflectionFrag->getGlProgram());

	// Fb
	m_r->createRenderTarget(m_width, m_height, GL_RGB, GL_RGB8, 
		GL_UNSIGNED_BYTE, 1, m_rt);

	GlManager& gl = GlManagerSingleton::get();
	GlJobChainHandle jobs(&gl);

	m_fb = GlFramebufferHandle(jobs, {{m_rt, GL_COLOR_ATTACHMENT0}});

	jobs.finish();
}

//==============================================================================
void Sslr::run(GlJobChainHandle& jobs)
{
	ANKI_ASSERT(m_enabled);

	m_fb.bind(jobs, true);
	jobs.setViewport(0, 0, m_width, m_height);

	m_r->drawQuad(jobs);
}


} // end namespace anki
