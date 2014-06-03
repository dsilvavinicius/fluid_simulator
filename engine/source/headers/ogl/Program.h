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
		Program(const string& vertFileName, const string& fragFileName);

		/** Gets the OpenGL index of this Program. */
		GLuint getIndex();

		/** Tells OpenGL that this program will be used. */
		void use();
	protected:
		/** Final OpenGL shader program identifier. */
		ProgramInitializerPtr m_programInit;

		/** Derived Programs should init uniforms here. */
		virtual void initUniforms() = 0;
	};
	
	typedef shared_ptr<Program> ProgramPtr;
}

#endif