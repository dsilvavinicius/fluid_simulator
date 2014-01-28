#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <GL/freeglut.h>

using namespace::std;

/**
 * Application class. Instantiates and manages the window and controls the simulation loop.
 */
namespace Infrastructure {
	class Application
	{
	public:
		static shared_ptr<Application> instance;
		
		~Application();
		
		void createMainWindow(int* argc, char** argv);
		void enterSimulationLoop();
	
	private:
		Application();
		static void simulationLoop();
	};
}

#endif

