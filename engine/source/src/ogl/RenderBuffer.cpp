#include <stdexcept>

#include "ogl/RenderBuffer.h"
#include "ogl/OGL.h"

using namespace std;

namespace ogl
{
	RenderBuffer::RenderBuffer(GLenum attachmentType, GLenum internalFormat, GLenum readFormat, GLenum readType,
		vec2& size, const GLsizei samples)
	{
		m_size = size;
		m_attachmentType = attachmentType;
		m_internalFormat = internalFormat;
		m_readFormat = readFormat;
		m_readType = readType;
		m_samples = samples;

		glGenRenderbuffers(1, &m_index);
		glBindRenderbuffer(GL_RENDERBUFFER, m_index);
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, m_samples, m_internalFormat, m_size.x, m_size.y);

		OGL::checkError();
	}

	RenderBuffer::~RenderBuffer()
	{
		glDeleteRenderbuffers(1, &m_index);
	}

	GLenum RenderBuffer::getAttachmentType()
	{
        return m_attachmentType;
	}
}
