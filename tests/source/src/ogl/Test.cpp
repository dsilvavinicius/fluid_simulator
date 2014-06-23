#include "ogl/Test.h"
#include "ogl/DisplaySettings.h"

using namespace ogl;

namespace ogl
{
	namespace test
	{
		void Test::SetUp()
		{
            DisplaySettingsPtr displaySettings = make_shared<DisplaySettings>(
                DisplaySettings::DEFAULT_WIDTH, DisplaySettings::DEFAULT_HEIGHT);

			m_app = make_shared<Application>(displaySettings);
			m_app->createMainWindow();
		}

		void Test::TearDown()
		{
			m_app->tearDown();
		}
	}
}
