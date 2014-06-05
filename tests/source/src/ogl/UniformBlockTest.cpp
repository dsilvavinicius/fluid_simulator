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
			TestProgram() : Program(vertSource, fragSource) {
				initUniforms();
			}

			~TestProgram() {}
		protected:
			void initUniforms() {
				use();
				
				vec4 uniformValue{ 1.f, 1.f, 1.f, 1.f };
				
				vector<AnyUniformPtr> uniformVector;
				uniformVector.push_back(AnyUniformPtr(new AnyUniform("uniform0", uniformValue)));
				uniforms = UniformBlockPtr(new UniformBlock(string("Uniforms"), uniformVector));
				uniforms->transferToProgram(*this);
			}
		private:
			UniformBlockPtr uniforms;
			
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
			virtual void SetUp()
			{
				Test::SetUp();
				m_program = TestProgramPtr(new TestProgram());
			}

			TestProgramPtr m_program;
		};

		TEST_F(UniformBlockTest, Creation) {
		}
	}
}