#include <GL/glew.h>
#include "ogl/Program.h"
#include "ogl/OGL.h"

namespace ogl
{
	Program::Program(const string& vertSource, const string& fragSource)
	{
		m_programInit = make_shared<ProgramInitializer>(vertSource, fragSource);
	}


	GLuint Program::getIndex() {
		return m_programInit->getIndex();
	}

	void Program::use() {
		glUseProgram(m_programInit->getIndex());
		OGL::checkError();
	}
}