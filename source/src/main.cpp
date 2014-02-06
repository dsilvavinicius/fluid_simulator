#include <iostream>
#include <memory>
#include "Application.h"

using namespace std;

void main(int argc, char** argv) {
	shared_ptr<infrastructure::Application> application = infrastructure::Application::instance;
	application->createMainWindow(&argc, argv);
	application->enterSimulationLoop();
}