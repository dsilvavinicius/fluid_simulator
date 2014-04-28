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

		/** Subclasses should provide shader uniform initialization here. */
		virtual void initUniforms() = 0;
		/** Subclasses should provide render buffer initialization here. */
		virtual void initFrameBuffer(DisplaySettingsPtr& display) = 0;
	protected:
		/** Final OpenGL shader program identifier. */
		GLuint m_program;

		/** Framebuffer generated after program execution. */
		GLuint m_frameBufferId;
		GLuint m_renderBufferId;
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