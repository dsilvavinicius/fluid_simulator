#include <gtest/gtest.h>

#include "ogl/Test.h"
#include "ogl/UniformBlock.h"
#include "engine/RayDataBackPass.h"

using namespace ogl::test;

namespace ogl
{
	namespace test
	{
		class UniformBlockTest : public Test
		{
		public:
			virtual void SetUp()
			{
				Test::SetUp();

			}
		};

		class TestProgram : Program
		{
		public:
			TestProgram();
			~TestProgram();

		private:

		};


		TEST_F(Test, Creation) {
			ASSERT_NO_THROW({
				RayDataBackPass()
				UniformBlock();

			}
		);
	}
}