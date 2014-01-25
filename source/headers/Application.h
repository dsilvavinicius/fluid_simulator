#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <GL/freeglut.h>
#include "EntityManager.h"

using namespace::std;

namespace Infrastructure {
	class Application
	{
	public:
		Application();
		~Application();

	private:
		shared_ptr<EntityManager> entityManager;

		void createMainWindow();
		void beginGameLoop();
		void gameLoop();
	};
}

#endif

