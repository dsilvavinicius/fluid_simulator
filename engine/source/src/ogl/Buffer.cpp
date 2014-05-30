#include "ogl/Buffer.h"
#include "ogl/OGL.h"

namespace ogl {
	Buffer::Buffer(GLenum type, GLsizeiptr size, const GLvoid *data, GLenum usage) {
		m_size = size;
		
		glGenBuffers(1, &m_bufferId);
		glBindBuffer(type, m_bufferId);
		glBufferData(type, size, data, usage);

		OGL::checkError();
	}

	Buffer::~Buffer() {
		glInvalidateBufferData(m_bufferId);
	}

	GLsizeiptr const Buffer::getSize() {
		return m_size;
	}
}