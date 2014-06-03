#ifndef PROGRAM_H
#define PROGRAM_H

#include "ogl/ProgramInitializer.h"

using namespace std;

/**
 * An OpenGL shader program. Has a vertex and fragment shader and a framebuffer. 
 */
namespace ogl
{	
	class Program
	{
	public:
		Program(const string& vertSource, const string& fragSource);

		/** Gets the OpenGL index of this Program. */
		GLuint getIndex();

		/** Tells OpenGL that this program will be used. */
		void use();
	protected:
		/** Final OpenGL shader program identifier. */
		ProgramInitializerPtr m_programInit;
	};
	
	typedef shared_ptr<Program> ProgramPtr;
}

#endif