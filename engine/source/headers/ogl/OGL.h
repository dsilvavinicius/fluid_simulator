#ifndef OGL_H
#define OGL_H

#include <GL/glew.h>

namespace ogl {
	class OGL {
	private:
		OGL();
	public:
		/** @throws logic_error case any error flag is found in OpenGL. */
		static void checkError();

		/** Returns the size of an OpenGL type in bytes. */
		static size_t getTypeSize(GLenum type);
	};
}
#endif