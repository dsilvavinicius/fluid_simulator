#include <stdexcept>
#include <gl/glew.h>
#include "ogl/Application.h"

namespace ogl {
	
	Application& Application::getInstance() {
		static Application app;
		return app;
	}

	Application::Application() {}


	Application::~Application() {}

	void Application::createMainWindow() {
		// Dummy argc and argv;
		int argc = 1;
		char* argv = { "" };
		glutInit(&argc, &argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(640, 480);
		glutCreateWindow("My First Triangle");
		if (glewInit() != GLEW_OK) {
			throw runtime_error("GLEW cannot be initialized.");
		}
	}

	void Application::enterSimulationLoop() {
		glutDisplayFunc(&(Application::simulationLoop));
		glutMainLoop();
	}

	void Application::simulationLoop() {
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
		
		glColor3f(1.f, 0.f, 0.f);
		glBegin(GL_TRIANGLES);
			glVertex2f(0.f, 0.f);
			glVertex2f(1.f, 0.f);
			glVertex2f(1.f, 1.f);
		glEnd();

		glutSwapBuffers();
	}
}