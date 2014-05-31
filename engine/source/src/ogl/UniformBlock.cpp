#include "ogl/UniformBlock.h"

namespace ogl
{
	UniformBlock::UniformBlock(string& name, UniformBufferPtr& buffer)
	{
		m_name = name;
		m_buffer = buffer;
	}

	UniformBlock::~UniformBlock() {}

	void UniformBlock::initInProgram(ProgramPtr& program)
	{
		GLuint bindingPoint = 1;
		m_index = glGetUniformBlockIndex(program->getIndex(), m_name.c_str());
		glUniformBlockBinding(program->getIndex(), m_index, bindingPoint);

		glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, m_buffer->getIndex());
	}
}