#include <iostream>
#include <memory>
#include "Application.h"

using namespace std;

void main(int argc, char** argv) {
	shared_ptr<Infrastructure::Application> application = Infrastructure::Application::instance;
	application->createMainWindow(&argc, argv);
	application->enterSimulationLoop();
}