#ifndef RENDER_BUFFER_H
#define RENDER_BUFFER_H

#include <utility>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

namespace ogl
{
	/** Encapsulates OpenGL renderbuffers. */
	class RenderBuffer
	{
	public:
		/** @param attachmentType GL_COLOR_ATTACHMENTi, GL_DEPTH_ATTACHMENT, etc.
			@param internalFormat GL_RGBA32F, GL_R16UI, etc.
			@param readFormat GL_RGBA, GL_BGRA, etc.
			@param readType GL_FLOAT, GL_UNSIGNED_INT_24_8, etc.
			@param size .x is the width and .y is the height of the framebuffer in pixels.
			@param samples number of samples for multisample rendering. */
		RenderBuffer(GLenum attachmentType, GLenum internalFormat, GLenum readFormat, GLenum readType,
			vec2& size, const GLsizei samples = 1);

		~RenderBuffer();

        GLenum getAttachmentType();

	protected:
		/** OpenGL index of this renderbuffer. */
		GLuint m_index;

		/** Size of this renderbuffer. */
		vec2 m_size;

		/** The attachment that this renderbuffer represents in a framebuffer. */
		GLenum m_attachmentType;

		/** OpenGL internal format. Used to specify storage for this buffer. GL_RGBA8, for example. */
		GLenum m_internalFormat;

		/** OpenGL read format for this renderbuffer. GL_RGBA, for example. */
		GLenum m_readFormat;

		/** OpenGL read data type for this renderbuffer. GL_FLOAT, for example. */
		GLenum m_readType;

		/** Number of samples of this renderbuffer. */
		GLsizei m_samples;
	};

	typedef shared_ptr<RenderBuffer> RenderBufferPtr;
}
#endif
