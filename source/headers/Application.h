#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <GL/freeglut.h>

using namespace::std;

/**
 * Application class. Instantiates and manages the window and controls the simulation loop.
 */
namespace infrastructure {
	class Application
	{
	public:
		static Application& getInstance();
		~Application();
		void createMainWindow(int* argc, char** argv);
		void enterSimulationLoop();
	
	private:
		Application();
		Application(Application const&);
		void operator=(Application const&);
		static void simulationLoop();
	};
}

#endif

