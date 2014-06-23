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
			virtual void TearDown();

		protected:
			ApplicationPtr m_app;
		};
	}
}
#endif
