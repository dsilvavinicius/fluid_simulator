#ifndef TEST_H
#define TEST_H

#include <gtest/gtest.h>
#include "infrastructure/Application.h"

namespace infrastructure
{
	/** Base test class. */
	class Test : public ::testing::Test
	{
	public:
		virtual void SetUp();

	private:
		ApplicationPtr m_app;
	};
}

#endif
