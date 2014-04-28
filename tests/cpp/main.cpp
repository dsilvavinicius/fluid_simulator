#include <gtest/gtest.h>
#include "RayDataBackPass.h"
#include "OGL.h"

using namespace engine;
using namespace ogl;

TEST(RayDataBackPassTest, Creation) {
	ASSERT_NO_THROW(RayDataBackPass program());
	ASSERT_NO_THROW(OGL::checkError());
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}