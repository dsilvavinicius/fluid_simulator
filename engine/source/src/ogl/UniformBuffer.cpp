#include "ogl/UniformBuffer.h"

namespace ogl
{
	UniformBuffer::UniformBuffer(GLsizeiptr size,  GLvoid* const data, GLenum usage) :
		Buffer(GL_UNIFORM_BUFFER, size, data, usage)
	{
	}
}