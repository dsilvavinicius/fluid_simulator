#include "ogl/Buffer.h"
#include "ogl/OGL.h"

namespace ogl
{
	Buffer::Buffer(GLenum type, GLsizeiptr size, const GLvoid *data, GLenum usage)
	{
		m_size = size;
		
		glGenBuffers(1, &m_index);
		glBindBuffer(type, m_index);
		glBufferData(type, size, data, usage);

		OGL::checkError();
	}

	Buffer::~Buffer()
	{
		glInvalidateBufferData(m_index);
	}

	GLuint Buffer::getIndex() const { return m_index; }

	GLsizeiptr Buffer::getSize() const { return m_size; }
}