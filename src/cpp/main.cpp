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
	catch (const runtime_error& e) {
		cerr << "Runtime error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << "Error ocurred: " << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown error ocurred." << endl;
	}
}