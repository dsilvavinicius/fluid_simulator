#include "infrastructure/Test.h"

using namespace ogl;

namespace ogl
{
	namespace test
	{
		void Test::SetUp() {
			m_app = ApplicationPtr(&Application::getInstance());
			m_app->createMainWindow();
		}
	}
}