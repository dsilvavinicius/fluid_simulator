#include <gtest/gtest.h>

#include "infrastructure/Test.h"
#include "ogl/UniformBlock.h"

using namespace infrastructure;

TEST_F(Test, Creation) {
	ASSERT_NO_THROW({
		UniformBlock();

	});
}
