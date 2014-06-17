#ifndef COLOR_BUFFER_H
#define COLOR_BUFFER_H

#include <memory>
#include <GL/glew.h>

#include "ogl/RenderBuffer.h"

namespace ogl {
	class ColorBuffer : public RenderBuffer
	{
	public:
		/** @copydoc RenderBuffer::RenderBuffer()
			@param colorIndex is the index of this color buffer among the others (< GL_MAX_COLOR_ATTACHMENTS). */
		ColorBuffer(GLuint colorIndex, GLenum internalFormat, GLenum readFormat, GLenum readType,
			vec2& size, const GLsizei samples = 1);

		~ColorBuffer();

		/** Clear this buffer with the color. */
		void clear(vec4 color);

		/** Sets this renderbuffer to be writeable by shaders. */
		void setDrawable();

		/** Enables capabilities for this renderbuffer. Just a wrapper for glEnablei(). */
		void enable(GLenum capability);

		/** Disables capabilities for this renderbuffer. Just a wrapper for glDisablei(). */
		void disable(GLenum capability);

		/** Checks whether a capability is enabled. Just a wrapper for glIsEnabledi(). */
		bool isEnabled(GLenum capability);

		/** Reads a rectangle of pixels from this renderbuffer. */
		void read(vec2& pos, vec2& size, vec4* pixels);
	private:
		GLuint m_colorIndex;
	};

	typedef shared_ptr<ColorBuffer> ColorBufferPtr;
}
#endif
