#include "ogl/SimpleTestProgram.h"

namespace ogl
{
    namespace test
    {
        const string SimpleTestProgram::vertSource =
            "#version 330 core\n"
            "uniform Uniforms {"
            "	vec4 uniform0;"
            "};"
            "void main() {"
            "	gl_Position = uniform0;"
            "}";
        const string SimpleTestProgram::fragSource =
            "#version 330 core\n"
            "in vec4 pos;"
            "out vec4 finalColor;"
            "void main() {"
            "	finalColor = pos;"
            "}";

        SimpleTestProgram::SimpleTestProgram(vector<UniformBlockPtr>& uniformBlocks) :
            Program(vertSource, fragSource, uniformBlocks) {}

        SimpleTestProgram::SimpleTestProgram(vector<UniformBlockPtr>& uniformBlocks, FrameBufferPtr& framebuffer) :
            Program(vertSource, fragSource, uniformBlocks, framebuffer) {}

        SimpleTestProgram::~SimpleTestProgram() {}
    }
}
