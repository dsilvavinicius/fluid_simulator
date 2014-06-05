#ifndef UNIFORM_BLOCK_H
#define UNIFORM_BLOCK_H

#include <vector>
#include <map>

#include "ogl/Program.h"
#include "ogl/Uniform.h"
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
		UniformBlock(string& name, vector<AnyUniformPtr>& uniforms);
		~UniformBlock();

		/** Changes the value of an uniform */
		template <typename T>
		void change(string uniformName, T value);

		/** Transfer this uniform block to the passed program. */
		void transferToProgram(Program& program);

	protected:
		/** Uniform map. The key is the name of the uniform in shader and the value is the actual uniform. */
		map<string, AnyUniformPtr> m_uniforms;

		/** Buffer used to transfer data do GPU. */
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