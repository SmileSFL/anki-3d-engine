#ifndef ANKI_GL_FBO_H
#define ANKI_GL_FBO_H

#include "anki/util/Assert.h"
#include "anki/util/Exception.h"
#include "anki/gl/Gl.h"
#include <initializer_list>
#include <atomic>


namespace anki {

class Texture;

/// @addtogroup gl
/// @{

/// Frame buffer object. The class is actually a wrapper to avoid common 
/// mistakes. It only supports binding at both draw and read targets
class Fbo
{
public:
	/// @name Constructors/Destructor
	/// @{
	Fbo()
	{}

	~Fbo();
	/// @}

	/// @name Accessors
	/// @{
	GLuint getGlId() const
	{
		ANKI_ASSERT(isCreated());
		return glId;
	}

	uint32_t getUuid() const
	{
		return uuid;
	}
	/// @}

	/// Binds FBO
	void bind() const;

	/// Unbinds the FBO
	void unbind() const;

	/// Unbind all
	///
	/// Unbinds both draw and read FBOs so the active is the default FBO
	static void unbindAll();

	/// Returns true if the FBO is ready for draw calls
	bool isComplete() const;

	/// Set the color attachments of this FBO
	void setColorAttachments(const std::initializer_list<const Texture*>& 
		textures);

	/// Set other attachment
	void setOtherAttachment(GLenum attachment, const Texture& tex);

	/// Creates a new FBO
	void create();

	/// Destroy it
	void destroy();

private:
	static std::atomic<uint32_t> counter;
	GLuint glId = 0; ///< OpenGL identification
	uint32_t uuid; ///< A unique unique identifier. It changes on create

	bool isCreated() const
	{
		return glId != 0;
	}

	static GLuint getCurrentDrawFboGlId()
	{
		GLint i;
		glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &i);
		return i;
	}

	static GLuint getCurrentReadFboGlId()
	{
		GLint i;
		glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &i);
		return i;
	}
};
/// @}

} // end namespace

#endif