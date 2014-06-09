#include "ogl/Test.h"

using namespace ogl;

namespace ogl
{
	namespace test
	{
		void Test::SetUp()
		{
			m_app = make_shared<Application>();
			m_app->createMainWindow();
		}

		void Test::TearDown()
		{
			m_app->tearDown();
		}
	}
}