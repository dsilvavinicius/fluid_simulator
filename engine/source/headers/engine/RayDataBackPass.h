#ifndef RAY_DATA_BACK_PASS_H
#define RAY_DATA_BACK_PASS_H

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp> 
#include "ogl/Program.h"

using namespace glm;
using namespace ogl;

/**
 * Back face pass to generate RayData. http://http.developer.nvidia.com/GPUGems3/gpugems3_ch30.html
 * section 30.3.1.
 */
namespace engine {
	class RayDataBackPass : public Program {
	public:
		RayDataBackPass(mat4 modelView, mat4 Projection, vec3 camPos);
		~RayDataBackPass();
		void initUniforms();
	protected:
		void initFrameBuffer(DisplaySettingsPtr& display);
		void clearRenderBuffers();
	private:
		static const char *m_vertShaderFileName;
		static const char *m_fragShaderFileName;
		
		/** Framebuffer generated after program execution. */
		GLuint m_frameBufferId;
		/** Renderbuffer attached to m_frameBufferId. */
		GLuint m_renderBufferId;
	};

	typedef shared_ptr<RayDataBackPass> RayDataBackPassPtr;
}
#endif