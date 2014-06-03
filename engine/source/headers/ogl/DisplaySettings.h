#ifndef DISPLAY_SETTINGS_H
#define DISPLAY_SETTINGS_H

#include <memory>

using namespace std;

namespace ogl {
	/**
	 * Display Settings for programs.
	 */
	class DisplaySettings
	{
	public:
		DisplaySettings(int resHeight, int resWidth);
		~DisplaySettings();

		static const int DEFAULT_WIDTH = 1280;
		static const int DEFAULT_HEIGHT = 1024;

		int getResWidth();
		int getResHeight();

	private:
		int m_resWidth;
		int m_resHeight;
	};

	typedef shared_ptr<DisplaySettings> DisplaySettingsPtr;
}

#endif