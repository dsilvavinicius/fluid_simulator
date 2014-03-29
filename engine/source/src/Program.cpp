#include <fstream>
#include <GL/glew.h>
#include "Program.h"
#include "Utils.h"

using namespace utils;

namespace engine {
	
	const int Program::LOG_SIZE = 5000;
	
	/**
	 * Creates and compiles the post-processing program shaders.
	 */
	Program::Program(const string& vertFileName, const string& fragFileName) {
		m_vert = createShader(vertFileName, GL_VERTEX_SHADER);
		m_frag = createShader(fragFileName, GL_FRAGMENT_SHADER);

		m_program = glCreateProgram();
		glAttachShader(m_program, m_vert);
		glAttachShader(m_program, m_frag);

		// Linking.
		glLinkProgram(m_program);

		GLint linkFlag;
		glGetProgramiv(m_program, GL_LINK_STATUS, &linkFlag);
		
		if (linkFlag != GL_TRUE) {
			char log[LOG_SIZE];
			glGetProgramInfoLog(m_program, LOG_SIZE, NULL, log);

			throw new runtime_error(log);
		}
		
		// Creating framebuffer and renderbuffer.
		glGenFramebuffers(1, &m_frameBufferId);
		glBindFramebuffer(GL_DRAW_BUFFER, m_frameBufferId);

		Utils::checkGLError();

		initUniforms();
		initRenderBuffers();
	}


	Program::~Program(){
		glDeleteShader(m_vert);
		glDeleteShader(m_frag);
		glDeleteProgram(m_program);
		glDeleteFramebuffers(1, &m_frameBufferId);

		Utils::checkGLError();
	}

	/**
	 * Creates a shader given the source file name and type.
	 */
	GLint Program::createShader(const string& fileName, const GLenum type) {
		const char* source[1] = { Utils::loadFile(fileName).c_str() };
		
		GLint shader = glCreateShader(type);

		if (shader == 0) {
			throw new runtime_error("Vertex shader creation has reported error.");
		}

		glShaderSource(shader, 1, source, NULL);

		compileShader(shader);

		return shader;
	}

	/**
	 * Compiles a shader.
	 */
	void Program::compileShader(GLuint shader) {
		glCompileShader(shader);
		GLint compilationFlag;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationFlag);

		if (compilationFlag != GL_TRUE) {
			char log[Program::LOG_SIZE];
			glGetShaderInfoLog(shader, LOG_SIZE, NULL, log);

			throw new runtime_error(log);
		}
	}
}