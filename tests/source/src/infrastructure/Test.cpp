#include "infrastructure/Test.h"

namespace infrastructure
{
	void Test::SetUp() {
		m_app = ApplicationPtr(&Application::getInstance());
		m_app->createMainWindow();
	}
}