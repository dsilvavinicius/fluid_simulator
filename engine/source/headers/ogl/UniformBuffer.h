#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H

#include "ogl/Buffer.h"

namespace ogl
{
	class UniformBuffer : public Buffer
	{
	public:
		UniformBuffer(GLsizeiptr size, const GLvoid *data, GLenum usage);
		~UniformBuffer();

	private:
	};

	typedef shared_ptr<UniformBuffer> UniformBufferPtr;
}

#endif