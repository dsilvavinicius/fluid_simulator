#include <fstream>
#include <GL/glew.h>
#include "ogl/ProgramInitializer.h"
#include "infrastructure/Utils.h"
#include "ogl/OGL.h"

using namespace utils;

namespace ogl {
	
	const int ProgramInitializer::LOG_SIZE = 5000;

	ProgramInitializer& ProgramInitializer::newProgramInitializer(const string& vertSource,
		const string& fragSource)
	{
		ProgramInitializer& init = ProgramInitializer(vertSource, fragSource);
		return init;
	}

	ProgramInitializer::ProgramInitializer(const string& vertSource, const string& fragSource) {
		m_vert = createShader(vertSource, GL_VERTEX_SHADER);
		m_frag = createShader(fragSource, GL_FRAGMENT_SHADER);

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


	ProgramInitializer::~ProgramInitializer(){
		glDeleteShader(m_vert);
		glDeleteShader(m_frag);
		glDeleteProgram(m_index);

		OGL::checkError();
	}

	GLuint ProgramInitializer::getIndex() {
		return m_index;
	}

	GLint ProgramInitializer::createShader(const string& source, const GLenum type) {
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
	void ProgramInitializer::compileShader(GLuint shader) {
		glCompileShader(shader);
		GLint compilationFlag;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationFlag);

		if (compilationFlag != GL_TRUE) {
			char log[ProgramInitializer::LOG_SIZE];
			glGetShaderInfoLog(shader, LOG_SIZE, NULL, log);

			throw logic_error(log);
		}
	}
}