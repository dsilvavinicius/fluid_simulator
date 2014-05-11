#include <stdexcept>
#include <GL/glew.h>
#include "OGL.h"

using namespace std;

namespace ogl {
	OGL::OGL() {}

	void OGL::checkError() {
		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			throw new logic_error("Error in OpenGL: " + error);
		}
	}
}