#include "ogl/UniformBlock.h"
#include "ogl/OGL.h"

namespace ogl
{
	int UniformBlock::m_bindingIndexSeed = 0;

	UniformBlock::UniformBlock(string& name, vector<AnyUniformPtr>& uniforms)
	{
		m_name = name;
		for (auto& uni : uniforms) {
			m_uniforms[uni->getName()] = uni;
		}
		m_bindingIndex = generateBindingIndex();
		m_buffer = nullptr;
	}

	UniformBlock::~UniformBlock() {}

	template <typename T>
	void UniformBlock::change(string uniformName, T value)
	{
		m_uniforms[uniformName]->setValue(value);
	}

	int UniformBlock::generateBindingIndex() {
		return  m_bindingIndexSeed++;
	}

	void UniformBlock::transferToProgram(Program& program)
	{
		program.use();
		
		GLuint programIndex = program.getIndex();
		auto blockIndex = glGetUniformBlockIndex(programIndex, m_name.c_str());
		GLint dataSize;
		glGetActiveUniformBlockiv(programIndex, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &dataSize);

		OGL::checkError();

		if (!m_buffer)
		{
			m_buffer = UniformBufferPtr(new UniformBuffer(dataSize, GL_STATIC_DRAW));
		}
		m_buffer->update(programIndex, m_uniforms);

		glBindBufferBase(GL_UNIFORM_BUFFER, m_bindingIndex, m_buffer->getIndex());
		glUniformBlockBinding(programIndex, blockIndex, m_bindingIndex);

		OGL::checkError();
	}
}