#ifndef FLUID_2D_H
#define FLUID_2D_H

#include <glm/glm.hpp>

/**
 * 3D fluid class. The implementation follows the guidelines here:
 * http://http.developer.nvidia.com/GPUGems3/gpugems3_ch30.html. 
 */
namespace engine{
	class Fluid3D {
	public:
		Fluid3D(int gridWidth, int gridHeight);
		~Fluid3D();

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
		int gridWidth;
		int gridHeight;
	};
}
#endif