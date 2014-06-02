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
		Test();
		virtual ~Test();

	private:
		ApplicationPtr m_app;
	};
}

#endif
