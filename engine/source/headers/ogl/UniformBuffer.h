#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H

#include <map>
#include "ogl/Buffer.h"
#include "ogl/Uniform.h"

namespace ogl
{
	class UniformBuffer : public Buffer
	{
	public:
		UniformBuffer(GLsizei& size, GLenum usage);
		
		/** Updates this buffer with the uniform values in the map. */
		void update(GLuint& programIndex, map<string, AnyUniformPtr>& uniforms);
	};

	typedef shared_ptr<UniformBuffer> UniformBufferPtr;
}

#endif