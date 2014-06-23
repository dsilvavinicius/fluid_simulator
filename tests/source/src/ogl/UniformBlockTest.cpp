#include <gtest/gtest.h>

#include "ogl/Test.h"
#include "ogl/SimpleTestProgram.h"
#include "ogl/UniformBlock.h"

using namespace ogl::test;

namespace ogl
{
	namespace test
	{
		class UniformBlockTest : public Test
		{
		protected:
			void SetUp()
			{
				Test::SetUp();

				vec4 uniformValue{ 1.f, 1.f, 1.f, 1.f };

				vector<AnyUniformPtr> uniformVector;
				uniformVector.push_back(AnyUniformPtr(new AnyUniform("uniform0", uniformValue)));

				vector<UniformBlockPtr> uniformBlocks;
				string blockName = string("Uniforms");
				UniformBlockPtr uniformBlock = make_shared<UniformBlock>(blockName, uniformVector);
                uniformBlocks.push_back(uniformBlock);

				m_program = make_shared<SimpleTestProgram>(uniformBlocks);
			}

			SimpleTestProgramPtr m_program;
		};

		TEST_F(UniformBlockTest, Creation) {
		}
	}
}
