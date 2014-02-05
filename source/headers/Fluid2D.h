#ifndef FLUID_2D_H
#define FLUID_2D_H

/**
 * 2D fluid class. The implementation follows the guidelines here:
 * http://http.developer.nvidia.com/GPUGems/gpugems_ch38.html. 
 */
namespace fluid{
	class Fluid2D {
	public:
		Fluid2D(int gridWidth, int gridHeight);
		~Fluid2D();

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