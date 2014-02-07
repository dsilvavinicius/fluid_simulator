#include <iostream>
#include <memory>
#include "Application.h"

using namespace std;

void main(int argc, char** argv) {
	infrastructure::Application& application = infrastructure::Application::getInstance();
	application.createMainWindow(&argc, argv);
	application.enterSimulationLoop();
}