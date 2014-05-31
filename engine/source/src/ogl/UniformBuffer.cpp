#include "ogl/UniformBuffer.h"

namespace ogl
{
	UniformBuffer::UniformBuffer(GLsizeiptr size, const GLvoid *data, GLenum usage) :
		Buffer(GL_UNIFORM_BUFFER, size, data, usage)
	{
	}

	UniformBuffer::~UniformBuffer()
	{
	}
}