#include "ogl/Uniform.h"

namespace ogl
{
	string& AnyUniform::getName() { return m_name; }

	GLvoid* AnyUniform::getRawValue() { return m_rawValue; }
}