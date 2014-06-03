#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H

#include "ogl/Buffer.h"

namespace ogl
{
	class UniformBuffer : public Buffer
	{
	public:
		UniformBuffer(GLsizeiptr size, GLvoid* const data, GLenum usage);

	private:
	};

	typedef shared_ptr<UniformBuffer> UniformBufferPtr;
}

#endif