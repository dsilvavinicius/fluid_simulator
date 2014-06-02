#ifndef UNIFORM_BLOCK_TEST_H
#define UNIFORM_BLOCK_TEST_H

#include <gtest/gtest.h>
#include "infrastructure/Test.h"

TEST(UniformBlockTest, Creation) {
	ASSERT_NO_THROW({
		new UniformBlock
	});
}
#endif
