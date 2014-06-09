#include "ogl/UniformBuffer.h"
#include "ogl/OGL.h"

namespace ogl
{
	UniformBuffer::UniformBuffer(GLsizei& size, GLenum usage) :
		Buffer(GL_UNIFORM_BUFFER, size, usage) {}

	UniformBuffer::~UniformBuffer() {}

	void UniformBuffer::update(GLuint& programIndex, map<string, AnyUniformPtr>& uniforms)
	{
		const GLsizei numUniforms = (GLsizei) uniforms.size();

		const char** names = (const char**)malloc(numUniforms * sizeof(char*));

		{
			int i = 0;
			for (auto& keyValue : uniforms)
			{
				auto uni = keyValue.second;
				names[i++] = uni->getName().c_str();
			}
		}

		GLuint* indices = (GLuint*)malloc(numUniforms * sizeof(GLuint));
		GLint* size = (GLint*)malloc(numUniforms * sizeof(GLint));
		GLint* offset = (GLint*)malloc(numUniforms * sizeof(GLint));
		GLint* type = (GLint*)malloc(numUniforms * sizeof(GLint));

		glGetUniformIndices(programIndex, numUniforms, names, indices);
		glGetActiveUniformsiv(programIndex, numUniforms, indices, GL_UNIFORM_OFFSET, offset);
		glGetActiveUniformsiv(programIndex, numUniforms, indices, GL_UNIFORM_SIZE, size);
		glGetActiveUniformsiv(programIndex, numUniforms, indices, GL_UNIFORM_TYPE, type);

		char* data = (char*)malloc(m_size);

		for (int i = 0; i < numUniforms; ++i)
		{
			GLvoid* value = uniforms[string(names[i])]->getRawValue();
			memcpy(data + offset[i], value,
				size[i] * OGL::getTypeSize(type[i]));
		}

		Buffer::update(data);

		free(data);
		free(names);
		free(indices);
		free(size);
		free(offset);
		free(type);

		OGL::checkError();
	}
}