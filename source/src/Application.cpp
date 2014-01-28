#include "Application.h"

namespace Infrastructure {
	shared_ptr<Application> Application::instance{ shared_ptr<Application>(new Application) };
	
	Application::Application() {

	}


	Application::~Application() {

	}

	void Application::createMainWindow(int* argc, char** argv) {
		/* Glut-related initialising functions */
		glutInit(argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(640, 480);
		glutCreateWindow("My First Triangle");
	}

	void Application::enterSimulationLoop() {
		glutDisplayFunc(&(Application::simulationLoop));
		glutMainLoop();
	}

	void Application::simulationLoop() {
		glColor3f(1.f, 0.f, 0.f);
		glBegin(GL_TRIANGLES);
			glVertex2f(0.f, 0.f);
			glVertex2f(1.f, 0.f);
			glVertex2f(1.f, 1.f);
		glEnd();
	}
}