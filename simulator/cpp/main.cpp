#include <iostream>
#include <memory>
#include <exception>
#include "infrastructure/Application.h"

using namespace std;
using namespace infrastructure;

int main(int argc, char** argv) {
	try {
		Application& application = Application::getInstance();
		application.createMainWindow();
		application.enterSimulationLoop();
	}
	catch (const logic_error& e) {
		cerr << "Logic error: " << e.what() << endl;
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