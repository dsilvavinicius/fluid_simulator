#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>
#include <string>
#include <GL/glew.h>

#include "DisplaySettings.h"

using namespace std;

/**
 * Shader Program class for post-processing effects. Each Program has a vertex and fragment shader and a framebuffer. 
 */
namespace engine {
	
	class Program
	{
	public:
		Program(const string& vertFileName, const string& fragFileName);
		~Program();

		/** Gets the OpenGL index of this Program. */
		GLuint getIndex();

		/** Tells OpenGL that this program will be used. */
		void use();
	protected:
		/** Final OpenGL shader program identifier. */
		GLuint m_index;
	private:
		/** Shader identifiers. */
		GLuint m_vert;
		GLuint m_frag;

		/** Compilation and link logs size. */
		const static int LOG_SIZE;

		GLint createShader(const string& fileName, const GLenum type);
		void compileShader(GLuint shader);
	};
	
	typedef shared_ptr<Program> ProgramPtr;
}

#endif