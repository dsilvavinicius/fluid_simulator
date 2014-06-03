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
		
			void initUniforms() {
				use();
				
				vec4 uniformValue{ 1.f, 1.f, 1.f, 1.f };
				
				UniformBufferPtr buffer = UniformBufferPtr(
					new UniformBuffer(sizeof(vec4), (GLvoid* const)&uniformValue, GL_STATIC_DRAW));
				
				uniforms = UniformBlockPtr(new UniformBlock(string("Uniforms"), buffer));
				uniforms->initInProgram(*this);
			}
		private:
			UniformBlockPtr uniforms;
			
			const string vertSource =
				"#version 330 core\n"
				"uniform Uniforms {"
				"	vec4 camPos;"
				"};"
				"void main() {"
				"}";
			const string fragSource =
				"#version 330 core\n"
				"void main() {"
				"}";
		};
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