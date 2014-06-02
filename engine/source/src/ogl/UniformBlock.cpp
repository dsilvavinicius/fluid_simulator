#include "ogl/UniformBlock.h"
#include "ogl/OGL.h"

namespace ogl
{
	int UniformBlock::m_bindingIndexSeed = 0;

	UniformBlock::UniformBlock(string& name, UniformBufferPtr& buffer)
	{
		m_name = name;
		m_buffer = buffer;
		m_bindingIndex = generateBindingIndex();
		glBindBufferBase(GL_UNIFORM_BUFFER, m_bindingIndex, m_buffer->getIndex());

		OGL::checkError();
	}

	UniformBlock::~UniformBlock() {}

	int UniformBlock::generateBindingIndex() {
		return  m_bindingIndexSeed++;
	}

	void UniformBlock::initInProgram(ProgramPtr& program)
	{
		program->use();
		
		m_index = glGetUniformBlockIndex(program->getIndex(), m_name.c_str());
		glUniformBlockBinding(program->getIndex(), m_index, m_bindingIndex);

		OGL::checkError();
	}
}