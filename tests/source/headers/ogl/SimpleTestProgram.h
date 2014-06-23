#ifndef SIMPLE_TEST_PROGRAM_H
#define SIMPLE_TEST_PROGRAM_H

#include "ogl/Program.h"

namespace ogl
{
    namespace test
    {
        /** Simple shader program for testing purposes. */
        class SimpleTestProgram : Program
        {
        public:
            SimpleTestProgram(vector<UniformBlockPtr>& uniformBlocks);

            SimpleTestProgram(vector<UniformBlockPtr>& uniformBlocks, FrameBufferPtr& framebuffer);

            ~SimpleTestProgram();
        private:

            static const string vertSource;
            static const string fragSource;

        };

        typedef shared_ptr<SimpleTestProgram> SimpleTestProgramPtr;
    }
}

#endif
