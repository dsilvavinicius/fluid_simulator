#include "engine\Program.h"
#ifndef UNIFORM_BLOCK_H
#define UNIFORM_BLOCK_H

#include <vector>
#include "engine/Program.h"
#include "ogl/UniformBuffer.h"

using namespace std;
using namespace engine;
using namespace ogl;

namespace ogl
{
	/**
	* Represents an OpenGL's uniform block and should be used to initialize shader programs' uniform data.
	*/
	class UniformBlock
	{
	public:
		UniformBlock(string& name, UniformBufferPtr& buffer);
		~UniformBlock();

		/** Init this uniform block in the passed program. */
		void initInProgram(ProgramPtr& program);

	protected:

		/** Indeix of this UniformBlock in OpenGl. */
		GLuint m_index;

		/** Buffer which has the UniformBlock actual data. */
		UniformBufferPtr m_buffer;

		/** Name of the Block inside the actual OpenGL program. */
		string m_name;
	};

	typedef shared_ptr<UniformBlock> UniformBlockPtr;
}

#endif