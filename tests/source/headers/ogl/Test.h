#ifndef TEST_H
#define TEST_H

#include <gtest/gtest.h>
#include "ogl/Application.h"

namespace ogl
{
	namespace test
	{
		/** Base test class. */
		class Test : public testing::Test
		{
		public:
			virtual void SetUp();

		private:
			ApplicationPtr m_app;
		};
	}
}
#endif
