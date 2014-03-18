#include <gtest/gtest.h>
#include "Program.h"

using namespace infrastructure;

TEST(ProgramTest, Creation) {
	EXPECT_THROW(
		Program program("fileName", "fileName"),
		runtime_error
	);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}