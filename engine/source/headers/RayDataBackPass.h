#ifndef RAY_DATA_BACK_PASS_H
#define RAY_DATA_BACK_PASS_H

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp> 
#include "Program.h"

using namespace glm;

/**
 * Back face pass to generate RayData. http://http.developer.nvidia.com/GPUGems3/gpugems3_ch30.html
 * section 30.3.1.
 */
namespace engine {
	class RayDataBackPass : Program {
	private:
		static const char *m_vertShaderFileName;
		static const char *m_fragShaderFileName;
	protected:
		void initUniforms();
		void initFrameBuffer(DisplaySettingsPtr& display);
		void clearUniforms();
		void clearRenderBuffers();
	public:
		RayDataBackPass(mat4 modelView, mat4 Projection, vec3 camPos);
	};
}
#endif