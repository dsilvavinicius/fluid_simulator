#include "infrastructure/Test.h"

namespace infrastructure
{
	Test::Test() {
		m_app = ApplicationPtr(&Application::getInstance());
		m_app->createMainWindow();
	}
}