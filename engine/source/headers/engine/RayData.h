#ifndef RAY_DATA_H
#define RAY_DATA_H

#include <glm/glm.hpp>
#include <memory>
#include "ogl/Program.h"

using namespace std;
using namespace ogl;

/**
 * One of the quad boundaries of the fluid. Used in the fluid rendering, to raycast into the Fluid3D.
 */
namespace engine{
//	class RayData {
//	public:
//		RayData(const glm::vec2& size);
//
//		/**
//		 * Renders the fluid quad is rendered with the internal grid program to evaluate cells and 4 lines
//		 * are rendered in the borders
//		 */
//		void render();
//	private:
//		shared_ptr<glm::vec2> size;
//
//		/**
//		 * Calculates the texture with the entry point and travelled depth in the volume for each fragment's
//		 * associated ray.
//		 */
//		ProgramPtr calcRayData;
//	};
}

#endif
