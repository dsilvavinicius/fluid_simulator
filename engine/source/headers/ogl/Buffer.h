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
		
		/** OpenGL index of this buffer. */
		GLuint getIndex() const;
		
		/** Size in bytes. */
		GLsizeiptr getSize() const;
	private:
		GLuint m_index;
		GLsizeiptr m_size;
	};

	typedef shared_ptr<Buffer> BufferPtr;
}
#endif