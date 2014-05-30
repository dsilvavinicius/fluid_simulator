#include <stdexcept>
#include <GL/glew.h>
#include "ogl/OGL.h"

using namespace std;

namespace ogl {
	OGL::OGL() {}

	void OGL::checkError() {
		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			throw logic_error("Error in OpenGL: " + error);
		}
	}
}