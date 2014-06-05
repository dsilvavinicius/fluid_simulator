#ifndef BUFFER_H
#define BUFFER_H

#include <utility>
#include <memory>
#include <gl/glew.h>

using namespace std;

namespace ogl {
	class Buffer
	{
	public:
		Buffer(GLenum type, GLsizeiptr size, GLenum usage, const GLvoid *data = nullptr);
		~Buffer();
		
		/** Updates the buffer contents. */
		void update(const GLvoid *data);

		/** OpenGL index of this buffer. */
		GLuint getIndex() const;
		
		/** Size in bytes. */
		GLsizeiptr getSize() const;
	protected:
		GLenum &m_type;
		GLenum &m_usage;
		GLuint m_index;
		GLsizeiptr &m_size;
	};

	typedef shared_ptr<Buffer> BufferPtr;
}
#endif