#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include "ogl/ProgramInitializer.h"
#include "ogl/UniformBlock.h"
#include "ogl/FrameBuffer.h"

using namespace std;

namespace ogl
{
    // Circular dependency fixes.
    class UniformBlock;
    typedef shared_ptr<UniformBlock> UniformBlockPtr;

    /** An OpenGL shader program. Has a vertex shader, fragment shader, a map of shader's uniform blocks
    * and a framebuffer. */
	class Program
	{
	public:
        /** @param vertSource the source of the vertex shader.
        *   @param fragSource the source of the fragment shader.
        *   @param uniforms a list of uniform blocks from which the uniform block map will be generated.
        *   @param framebuffer the framebuffer associated with this program. */
		Program(const string& vertSource, const string& fragSource, vector<UniformBlockPtr>& uniformBlocks,
            FrameBufferPtr framebuffer = nullptr);

		/** Gets the OpenGL index of this Program. */
		GLuint getIndex();

		/** Tells OpenGL that this program will be used. */
		void use();

		/** Flushes the uniform blocks data to device memory. */
		void flushBlocks();
	protected:
		ProgramInitializerPtr m_programInit;

		map<string, UniformBlockPtr> m_uniformBlocks;

		FrameBufferPtr m_framebuffer;
	};

	typedef shared_ptr<Program> ProgramPtr;
}

#endif
