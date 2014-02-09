#include <iostream>
#include <memory>
#include <exception>
#include "Application.h"

using namespace std;

void main(int argc, char** argv) {
	try {
		infrastructure::Application& application = infrastructure::Application::getInstance();
		application.createMainWindow(&argc, argv);
		application.enterSimulationLoop();
	}
	catch (...) {
		exception_ptr exceptionPtr = current_exception();
	}
}