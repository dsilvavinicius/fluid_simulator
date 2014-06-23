#include "ogl/FrameBuffer.h"
#include "ogl/OGL.h"

namespace ogl
{
	FrameBuffer::FrameBuffer(vector<RenderBufferPtr>& attachments)
	{
        for (RenderBufferPtr renderbuffer : attachments)
        {
            m_attachments[renderbuffer->getAttachmentType()] = renderbuffer;
        }
	}

    FrameBuffer::~FrameBuffer()
    {

    }

    ColorBufferPtr FrameBuffer::getColorBuffer(GLint index)
    {

    }

    RenderBufferPtr FrameBuffer::getDepthBuffer()
    {

    }

    RenderBufferPtr FrameBuffer::getStencilBuffer()
    {

    }
}
