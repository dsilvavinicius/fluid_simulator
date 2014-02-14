#include <gtest/gtest.h>
#include "Program.h"

TEST(ProgramTest, Creation) {
	EXPECT_THROW(
		infrastructure::Program program("fileName", CGprofile::CG_PROFILE_ARBFP1),
		runtime_error
	);
}