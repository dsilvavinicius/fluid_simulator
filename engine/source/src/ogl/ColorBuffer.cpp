#include <stdexcept>

#include "ogl/ColorBuffer.h"
#include "ogl/OGL.h"

using namespace std;

namespace ogl
{
	ColorBuffer::ColorBuffer(GLuint colorIndex, GLenum internalFormat, GLenum readFormat, GLenum readType,
		vec2& size, const GLsizei samples) :
		RenderBuffer((GLenum)(GL_COLOR_ATTACHMENT0 + colorIndex), internalFormat, readFormat, readType,
		size, samples)
	{
		m_colorIndex = colorIndex;
	}

	ColorBuffer::~ColorBuffer() {}

	void ColorBuffer::clear(vec4 color)
	{
		setDrawable();
		float fColor[4] = { color.r, color.g, color.b, color.a };
		glClearBufferfv(GL_COLOR, m_colorIndex, fColor);
	}

	void ColorBuffer::setDrawable()
	{
		glBindRenderbuffer(GL_RENDERBUFFER, m_index);
		glDrawBuffer(m_attachmentType);
	}

	void ColorBuffer::enable(GLenum capability)
	{
		glEnablei(capability, m_colorIndex);
	}

	void ColorBuffer::disable(GLenum capability)
	{
		glDisablei(capability, m_colorIndex);
	}

	bool ColorBuffer::isEnabled(GLenum capability)
	{
		return glIsEnabledi(capability, m_colorIndex);
	}

	void ColorBuffer::read(vec2& pos, vec2& size, vec4* pixels)
	{
		glReadBuffer(m_attachmentType);
		glReadPixels(pos.x, pos.y, size.x, size.y, m_readFormat, m_readType, pixels);
	}
}