#include <gtest/gtest.h>

#include "ogl/Test.h"
#include "ogl/UniformBlock.h"
#include "engine/RayDataBackPass.h"

using namespace ogl::test;

namespace ogl
{
	namespace test
	{
		/** Simple shader program for testing purposes. */
		class TestProgram : Program
		{
		public:
			TestProgram(vector<UniformBlockPtr>& uniformBlocks) : Program(vertSource, fragSource, uniformBlocks)
			{
			}

			~TestProgram() {}
		private:

			static const string vertSource;
			static const string fragSource;

		};

		const string TestProgram::vertSource =
			"#version 330 core\n"
			"uniform Uniforms {"
			"	vec4 uniform0;"
			"};"
			"void main() {"
			"	gl_Position = uniform0;"
			"}";
		const string TestProgram::fragSource =
			"#version 330 core\n"
			"in vec4 pos;"
			"out vec4 finalColor;"
			"void main() {"
			"	finalColor = pos;"
			"}";

		typedef shared_ptr<TestProgram> TestProgramPtr;

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

				m_program = TestProgramPtr(new TestProgram(uniformBlocks));
			}

			TestProgramPtr m_program;
		};

		TEST_F(UniformBlockTest, Creation) {
		}
	}
}
