#include "ogl/Uniform.h"

namespace ogl
{
	AnyUniform::~AnyUniform()
	{
        free(m_rawValue);
	};

	string& AnyUniform::getName() { return m_name; }

	GLvoid* AnyUniform::getRawValue() { return m_rawValue; }
}
