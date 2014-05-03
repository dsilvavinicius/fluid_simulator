#include "RayDataBackPass.h"
#include "DisplaySettings.h"
#include "OGL.h"

using namespace glm;
using namespace ogl;

namespace engine {
	
	const char* RayDataBackPass::m_vertShaderFileName = "../engine/source/src/shaders/RayDataBackPass.vert";
	const char* RayDataBackPass::m_fragShaderFileName = "../engine/source/src/shaders/RayDataBackPass.frag";

	RayDataBackPass::RayDataBackPass(mat4 modelView, mat4 projection, vec3 camPos)
	: Program(m_vertShaderFileName, m_fragShaderFileName) {
		
		// Creating framebuffer and renderbuffer.
		glGenFramebuffers(1, &m_frameBufferId);
		glBindFramebuffer(GL_DRAW_BUFFER, m_frameBufferId);

		initUniforms();
		DisplaySettingsPtr display = DisplaySettingsPtr(
			new DisplaySettings(DisplaySettings::DEFAULT_WIDTH, DisplaySettings::DEFAULT_HEIGHT)
			);
		initFrameBuffer(display);

		OGL::checkError();
	}

	RayDataBackPass::~RayDataBackPass() {
		glDeleteFramebuffers(1, &m_frameBufferId);
	}

	void RayDataBackPass::initUniforms() {
		// Init "Matrices" block in vertex shader.
		string blockName = "Matrices";
		GLint uboIndex = glGetUniformBlockIndex(m_program, blockName.c_str());
		if (uboIndex == GL_INVALID_INDEX) {
			throw new logic_error("Invalid uniform block name: " + blockName);
		}

		GLint uboSize;
		glGetActiveUniformBlockiv(m_program, uboIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &uboSize);
		//glBindBufferBase(GL_UNIFORM_BUFFER, uboIndex, );


		// Init "cameraPos" in frag shader.


		OGL::checkError();
	}
	
	void RayDataBackPass::initFrameBuffer(DisplaySettingsPtr& display) {
		glGenRenderbuffers(1, &m_renderBufferId);
		glBindRenderbuffer(GL_RENDERBUFFER, m_renderBufferId);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA32F, display->getResWidth(), display->getResHeight());
		OGL::checkError();

		glGenFramebuffers(1, &m_frameBufferId);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_frameBufferId);
		OGL::checkError();

		glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_renderBufferId);
		OGL::checkError();

		GLenum fbStatus = glCheckFramebufferStatus(m_frameBufferId);
		if (fbStatus != GL_FRAMEBUFFER_COMPLETE) {
			throw new logic_error("Framebuffer is not complete after initialization. Error: " + fbStatus);
		}
	}
}