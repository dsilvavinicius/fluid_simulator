#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace::std;

/**
 * OpenGL application class. Instantiates and manages the window and controls the loop.
 */
namespace ogl {
	class Application
	{
	public:
		static Application& getInstance();
		~Application();
		void createMainWindow();
		void enterSimulationLoop();
	
	private:
		Application();
		static void simulationLoop();
	};

	typedef shared_ptr<Application> ApplicationPtr;
}

#endif

