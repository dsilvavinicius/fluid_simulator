#ifndef PROGRAM_INITIALIZER_H
#define PROGRAM_INITIALIZER_H

#include <memory>
#include <string>
#include <GL/glew.h>

#include "DisplaySettings.h"

using namespace std;

/**
 * Initializer for OpenGL shader programs. Ensure that a program is compiled and have their uniforms initialized.
 */
namespace ogl {

	class ProgramInitializer
	{
	public:
		/**
		* Creates and compiles the post-processing program shaders.
		* Use the static factory to access this constructor.
		* @param vertSource: string with source of the vertex program.
		* @param fragSource: string with source of the frag program.
		*/
		ProgramInitializer(const string& vertSource, const string& fragSource);

		~ProgramInitializer();

		/** Gets the OpenGL index of this Program. */
		GLuint getIndex();

		/** Uses the OpenGL program initialized by this instance. */
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

		/**
		* Creates a shader given the source and type.
		*/
		GLint createShader(const string& source, const GLenum type);

		void compileShader(GLuint shader);
	};

	typedef shared_ptr<ProgramInitializer> ProgramInitializerPtr;
}

#endif
