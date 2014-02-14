#include <gtest/gtest.h>
#include "Program.h"

TEST(ProgramTest, Creation) {
	EXPECT_THROW(
		infrastructure::Program program("fileName", CGprofile::CG_PROFILE_ARBFP1),
		runtime_error
		);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}