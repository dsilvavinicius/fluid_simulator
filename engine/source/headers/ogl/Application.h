#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "ogl/DisplaySettings.h"

using namespace::std;

/**
 * OpenGL application class. Instantiates and manages the window and controls the loop.
 */
namespace ogl
{
	class Application
	{
	public:
		Application(DisplaySettingsPtr& displaySettings);
		~Application();
		/** Finished the main loop. */
		void tearDown();

		void createMainWindow();
		void enterSimulationLoop();

        DisplaySettings getDisplaySettings();

	private:
		static void simulationLoop();

		DisplaySettingsPtr m_displaySettings;
	};

	typedef shared_ptr<Application> ApplicationPtr;
}

#endif

