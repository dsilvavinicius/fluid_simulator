#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <glm/glm.hpp>
#include <memory>

using namespace std;

/**
 * One of the quad boundaries of the fluid. Used in the fluid rendering, to raycast into the Fluid3D.
 */
namespace engine{
	class Boundary {
	public:
		Boundary(const glm::vec2& size, const glm::mat4x4 transform);

		/**
		 * Updates the fluid state. A quad is rendered to update the internal cells and 4 lines are rendered to
		 * update the borders.
		 */
		void update();
		
		/**
		 * Renders the fluid quad is rendered with the internal grid program to evaluate cells and 4 lines
		 * are rendered in the borders 
		 */
		void render();
	private:
		shared_ptr<glm::vec2> size;
		shared_ptr<glm::mat4x4> transform;
	};
}
#endif