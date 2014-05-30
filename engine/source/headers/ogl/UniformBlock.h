#include "engine\Program.h"
#ifndef UNIFORM_BLOCK_H
#define UNIFORM_BLOCK_H

#include <vector>
#include "engine/Program.h"
#include "ogl/Buffer.h"

/**
 * Represents an OpenGL's uniform block and should be used to initialize shader programs' uniform data.
 * Has support to be used in several OpenGL's programs at the same time.
 */

using namespace std;
using namespace engine;
using namespace ogl;

namespace infrastructure
{
	class UniformBlock
	{
	public:
		UniformBlock();
		~UniformBlock();

		/** Init this uniform block in the passed program. */
		void initInProgram(ProgramPtr ptr);

	protected:
		BufferPtr buffer;

	private:
		/** List of Programs which have this UniformBlock. */
		vector<ProgramPtr> program;
	};

	typedef shared_ptr<UniformBlock> UniformBlockPtr;
}

#endif