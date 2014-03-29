#ifndef RAY_DATA_BACK_PASS_H
#define RAY_DATA_BACK_PASS_H

#include "glm/mat4x4.hpp"
#include "Program.h"

using namespace glm;

/**
 * Back face pass to generate RayData. http://http.developer.nvidia.com/GPUGems3/gpugems3_ch30.html
 * section 30.3.1.
 */
namespace engine {
	class RayDataBackPass : Program {
	private:
		static string m_vertShaderFileName;
		static string m_fragShaderFileName;
	protected:
		void initUniforms();
		void initRenderBuffers();
	public:
		RayDataBackPass(mat4 modelView, mat4 Projection);
	};
}
#endif