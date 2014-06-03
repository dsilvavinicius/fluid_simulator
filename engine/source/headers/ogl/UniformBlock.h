#ifndef UNIFORM_BLOCK_H
#define UNIFORM_BLOCK_H

#include <vector>
#include "ogl/Program.h"
#include "ogl/UniformBuffer.h"

using namespace std;
using namespace ogl;

namespace ogl
{
	/**
	* Represents an OpenGL's uniform block and should be used to initialize shader programs' uniform data.
	* Can be shared among Programs.
	*/
	class UniformBlock
	{
	public:
		UniformBlock(string& name, UniformBufferPtr& buffer);
		~UniformBlock();

		/** Init this uniform block in the passed program. */
		void initInProgram(ProgramPtr& program);

	protected:

		/** Index of this UniformBlock in OpenGl. */
		GLuint m_index;

		/** Buffer which has the UniformBlock actual data. */
		UniformBufferPtr m_buffer;

		/** Name of the Block inside the actual OpenGL program. */
		string m_name;
	private:
		/** Each uniform block is given an binding index generated using this value. */
		static int m_bindingIndexSeed;

		/** Generates a binding index and increments m_bindingIndexSeed. */
		static int generateBindingIndex();

		/** Binding index for this buffer. Should be used to share uniform blocks among programs.*/
		int m_bindingIndex;
	};

	typedef shared_ptr<UniformBlock> UniformBlockPtr;
}

#endif