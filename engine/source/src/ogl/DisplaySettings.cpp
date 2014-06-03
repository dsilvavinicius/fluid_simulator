#include "ogl/DisplaySettings.h"

namespace ogl {
	DisplaySettings::DisplaySettings(int resHeight, int resWidth) {
		m_resHeight = resHeight;
		m_resWidth = resWidth;
	}

	DisplaySettings::~DisplaySettings()
	{
	}

	int DisplaySettings::getResWidth() { return m_resWidth; }
	int DisplaySettings::getResHeight() { return m_resHeight; }
}