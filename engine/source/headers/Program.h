#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>
#include <string>
#include <GL/glew.h>

using namespace std;

/**
 * Shader Program class for post-processing effects. Each Program has a vertex and fragment shader. 
 */
namespace engine {
	
	class Program
	{
	public:
		Program(const string& vertFileName, const string& fragFileName);
		~Program();

		/** Subclasses should provide shader uniform initialization here. */
		virtual void initUniforms() = 0;
		/** Subclasses should provide render buffer initialization here. */
		virtual void initRenderBuffers() = 0;
	protected:
		/** Final OpenGL shader program identifier. */
		GLuint m_program;
	private:
		/** Shader identifiers. */
		GLuint m_vert;
		GLuint m_frag;
		
		/** Framebuffer generated after program execution. */
		GLuint m_frameBufferId;
		GLuint m_renderBufferId;

		/** Compilation and link logs size. */
		const static int LOG_SIZE;

		GLint createShader(const string& fileName, const GLenum type);
		void compileShader(GLuint shader);
	};
}

#endif