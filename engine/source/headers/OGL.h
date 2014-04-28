#ifndef OGL_H
#define OGL_H

#include <string>

using namespace std;

namespace ogl {
	class OGL {
	private:
		OGL();
	public:
		/**
		 * @throws logic_error case any error flag is found in OpenGL.
		 */
		static void checkError();
	};
}
#endif