#include "ogl/Buffer.h"
#include "ogl/OGL.h"

namespace ogl
{
	Buffer::Buffer(GLenum type, GLsizei& size, GLenum usage, const GLvoid *data) :
		m_type(type), m_usage(usage), m_size(size)
	{
		glGenBuffers(1, &m_index);
		glBindBuffer(m_type, m_index);

		if (data) {
			update(data);
		}

		OGL::checkError();
	}

	Buffer::~Buffer()
	{
		glInvalidateBufferData(m_index);
	}

	void Buffer::update(const GLvoid *data) {
		glBindBuffer(m_type, m_index);
		glBufferData(m_type, m_size, data, m_usage);

		OGL::checkError();
	}

	GLuint Buffer::getIndex() const { return m_index; }

	GLsizeiptr Buffer::getSize() const { return m_size; }
}