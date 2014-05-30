#ifndef BUFFER_H
#define BUFFER_H

#include <utility>
#include <memory>
#include <gl/glew.h>

using namespace std;

namespace ogl {
	class Buffer {
	public:
		Buffer(GLenum type, GLsizeiptr size, const GLvoid *data, GLenum usage);
		~Buffer();
		
		/** Size in bytes. */
		GLsizeiptr const getSize();
	private:
		GLuint m_bufferId;
		GLsizeiptr m_size;
	};

	typedef shared_ptr<Buffer> BufferPtr;
}
#endif