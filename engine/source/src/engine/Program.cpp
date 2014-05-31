#include <fstream>
#include <GL/glew.h>
#include "engine/Program.h"
#include "infrastructure/Utils.h"
#include "ogl/OGL.h"

using namespace utils;
using namespace ogl;

namespace engine {
	
	const int Program::LOG_SIZE = 5000;
	
	/**
	 * Creates and compiles the post-processing program shaders.
	 */
	Program::Program(const string& vertFileName, const string& fragFileName) {
		m_vert = createShader(vertFileName, GL_VERTEX_SHADER);
		m_frag = createShader(fragFileName, GL_FRAGMENT_SHADER);

		m_index = glCreateProgram();
		glAttachShader(m_index, m_vert);
		glAttachShader(m_index, m_frag);

		// Linking.
		glLinkProgram(m_index);

		GLint linkFlag;
		glGetProgramiv(m_index, GL_LINK_STATUS, &linkFlag);
		
		if (linkFlag != GL_TRUE) {
			char log[LOG_SIZE];
			glGetProgramInfoLog(m_index, LOG_SIZE, NULL, log);

			throw logic_error(log);
		}

		OGL::checkError();
	}


	Program::~Program(){
		glDeleteShader(m_vert);
		glDeleteShader(m_frag);
		glDeleteProgram(m_index);

		OGL::checkError();
	}

	GLuint Program::getIndex() {
		return m_index;
	}

	/**
	 * Creates a shader given the source file name and type.
	 */
	GLint Program::createShader(const string& fileName, const GLenum type) {
		string source = Utils::loadFile(fileName);
		
		const GLchar* sourceC = source.c_str();
		const GLint lenght = (GLint) source.length();
		
		GLint shader = glCreateShader(type);

		if (shader == 0) {
			throw runtime_error("Vertex shader creation has reported error.");
		}

		glShaderSource(shader, 1, &sourceC, &lenght);

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

			throw logic_error(log);
		}
	}

	void Program::use() {
		glUseProgram(m_index);
	}
}