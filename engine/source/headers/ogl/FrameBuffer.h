#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H

#include <memory>
#include <map>
#include <vector>
#include <GL/glew.h>

#include "ogl/RenderBuffer.h"
#include "ogl/ColorBuffer.h"

using namespace std;

namespace ogl {
	/** Encapsulates Opengl framebuffer. It can have color, depth and stencil attachments. */
	class FrameBuffer
	{
	public:
		FrameBuffer(vector<RenderBufferPtr>& attachments);
		~FrameBuffer();

		ColorBufferPtr getColorBuffer(GLint index);

		RenderBufferPtr getDepthBuffer();

		RenderBufferPtr getStencilBuffer();

		/** Copies the contents of this framebuffer to the other.*/
		void blit(shared_ptr<FrameBuffer>& frameBuffer);
	protected:
		/** OpenGL framebuffer index. */
		GLuint m_index;
		/** Renderbuffer attachments for this framebuffer. */
		map<GLenum, RenderBufferPtr> m_attachments;
	};

	typedef shared_ptr<FrameBuffer> FrameBufferPtr;
}
#endif
