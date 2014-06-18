#include <GL/glew.h>
#include "ogl/Program.h"
#include "ogl/OGL.h"

namespace ogl
{
	Program::Program(const string& vertSource, const string& fragSource, vector<UniformBlockPtr>& uniformBlocks,
            FrameBufferPtr framebuffer)
	{
		m_programInit = make_shared<ProgramInitializer>(vertSource, fragSource);
        m_framebuffer = framebuffer;

        for (UniformBlockPtr block : uniformBlocks)
        {
            m_uniformBlocks[block->getName()] = block;
        }

        flushBlocks();
	}

	GLuint Program::getIndex()
	{
		return m_programInit->getIndex();
	}

	void Program::use()
	{
		m_programInit->use();
	}

	void Program::flushBlocks()
	{
		for (pair<string, UniformBlockPtr> block : m_uniformBlocks)
		{
            block.second->flushToProgram(m_programInit);
		}
	}
}
