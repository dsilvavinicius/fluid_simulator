#include "RayDataBackPass.h"

namespace engine {
	string RayDataBackPass::m_vertShaderFileName = "../engine/source/src/shaders/RayDataBackPass.vert";
	string RayDataBackPass::m_fragShaderFileName = "../engine/source/src/shaders/RayDataBackPass.frag";
	
	RayDataBackPass::RayDataBackPass(mat4 modelView, mat4 projection)
	: Program(m_vertShaderFileName, m_fragShaderFileName) {
		
	}

	void RayDataBackPass::initUniforms() {
		string blockName = "Matrices";
		GLint uboIndex = glGetUniformBlockIndex(m_program, blockName.c_str());
		if (uboIndex == GL_INVALID_INDEX) {
			throw new runtime_error("Invalid uniform block name: " + blockName);
		}

		GLint uboSize;
		glGetActiveUniformBlockiv(m_program, uboIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &uboSize);
	}
	
	void RayDataBackPass::initRenderBuffers() {

	}
}