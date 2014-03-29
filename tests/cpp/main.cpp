#include <gtest/gtest.h>
#include "RayDataBackPass.h"
#include "Utils.h"

using namespace engine;
using namespace utils;

TEST(RayDataBackPassTest, Creation) {
	ASSERT_NO_THROW(RayDataBackPass program());
	ASSERT_NO_THROW(Utils::checkGLError());
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}