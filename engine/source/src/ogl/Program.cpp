#include <GL/glew.h>
#include "ogl/Program.h"
#include "ogl/OGL.h"

namespace ogl
{
	Program::Program(const string& vertFileName, const string& fragFileName) {
		m_programInit = ProgramInitializerPtr(
			&ProgramInitializer::newProgramInitializer(vertFileName, fragFileName, [this]() { initUniforms(); })
		);
	}

	GLuint Program::getIndex() {
		return m_programInit->getIndex();
	}

	void Program::use() {
		glUseProgram(m_programInit->getIndex());
	}
}