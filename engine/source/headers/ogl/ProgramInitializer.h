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
		/** Use this factory to create ProgramInitializers. Compiles shaders and init uniforms of an OpenGL program. */
		template<typename Func>
		static ProgramInitializer& newProgramInitializer(const string& vertFileName, const string& fragFileName,
			Func initUniforms)
		{
			ProgramInitializer& init = ProgramInitializer(vertFileName, fragFileName);
			initUniforms();
			return init;
		}
		
		~ProgramInitializer();

		/** Gets the OpenGL index of this Program. */
		GLuint getIndex();
	protected:
		/** Final OpenGL shader program identifier. */
		GLuint m_index;
	private:
		/** Shader identifiers. */
		GLuint m_vert;
		GLuint m_frag;

		/** Compilation and link logs size. */
		const static int LOG_SIZE;

		/** Use the static factory to access this constructor. */
		ProgramInitializer(const string& vertFileName, const string& fragFileName);

		GLint createShader(const string& fileName, const GLenum type);
		void compileShader(GLuint shader);
	};
	
	typedef shared_ptr<ProgramInitializer> ProgramInitializerPtr;
}

#endif