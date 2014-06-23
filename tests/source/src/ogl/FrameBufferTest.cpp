#include <gtest/gtest.h>

#include "ogl/FrameBuffer.h"
#include "ogl/ColorBuffer.h"
#include "ogl/Test.h"
#include "ogl/SimpleTestProgram.h"

using namespace ogl::test;

namespace ogl
{
	namespace test
	{
        class FrameBufferTest : public Test
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

                DisplaySettings displaySettings = m_app->getDisplaySettings();

                vector<RenderBufferPtr> attachments;
                vec2 bufferSize = vec2(displaySettings.getResWidth(), displaySettings.getResHeight());
                ColorBufferPtr colorBuffer = make_shared<ColorBuffer>(0, GL_RGBA32F, GL_RGBA, GL_FLOAT,
                    bufferSize);
                attachments.push_back(colorBuffer);
                FrameBufferPtr framebuffer = make_shared<FrameBuffer>(attachments);

				m_program = make_shared<SimpleTestProgram>(uniformBlocks, framebuffer);
			}

			SimpleTestProgramPtr m_program;
		};

		//TEST_F(FrameBufferTest, Creation_Cleaning_Input_And_Output) {
		//}
	}
}
