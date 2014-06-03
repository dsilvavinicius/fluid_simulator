#include "ogl/OGL.h"
#include "ogl/Buffer.h"
#include "ogl/DisplaySettings.h"
#include "engine/RayDataBackPass.h"
#include "infrastructure/Utils.h"

using namespace glm;
using namespace ogl;
using namespace utils;

namespace engine {
	
	const char* RayDataBackPass::m_vertShaderFileName = "../../engine/source/src/shaders/RayDataBackPass.vert";
	const char* RayDataBackPass::m_fragShaderFileName = "../../engine/source/src/shaders/RayDataBackPass.frag";

	RayDataBackPass::RayDataBackPass(mat4 modelView, mat4 projection, vec3 camPos)
		: Program(Utils::loadFile(m_vertShaderFileName), Utils::loadFile(m_fragShaderFileName)) {
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
		/*string blockName = "Matrices";
		GLint uboIndex = glGetUniformBlockIndex(getIndex(), blockName.c_str());
		
		if (uboIndex == GL_INVALID_INDEX) {
			throw logic_error("Invalid uniform block name: " + blockName);
		}
		
		GLsizeiptr uboSize;
		glGetActiveUniformBlockiv(m_index, uboIndex, GL_UNIFORM_BLOCK_DATA_SIZE, uboSize);

		Buffer buffer = Buffer(GL_UNIFORM_BUFFER, uboSize, buffer, GL_STATIC_DRAW);

		GLuint ubo;
		GLvoid *buffer;
		
		buffer = malloc(uboSize);

		if (buffer == NULL) {
			throw logic_error("Unable to allocate buffer\n");
		}*/

		
		//glBindBufferBase(GL_UNIFORM_BUFFER, uboIndex, );


		// Init "cameraPos" in frag shader.

		OGL::checkError();
	}
	
	void RayDataBackPass::initFrameBuffer(DisplaySettingsPtr& display) {
		// Creating framebuffer and renderbuffer.
		/*glGenFramebuffers(1, &m_frameBufferId);
		glBindFramebuffer(GL_DRAW_BUFFER, m_frameBufferId);
		
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
			throw logic_error("Framebuffer is not complete after initialization. Error: " + fbStatus);
		}*/
	}
}