#include <gtest/gtest.h>
#include <glm/glm.hpp>

#include "infrastructure/Test.h"
#include "engine/RayDataBackPass.h"

using namespace glm;
using namespace ogl::test;
using namespace engine;

namespace engine
{
	namespace test
	{
		class RayDataBackPassTest : public Test
		{
		protected:
			virtual void SetUp(){
				Test::SetUp();
				m_program = RayDataBackPassPtr(new RayDataBackPass(mat4(1.f), mat4(1.f), vec3(0.f)));
			}

			virtual void TearDown() {}

			RayDataBackPassPtr m_program;
		};

		TEST_F(RayDataBackPassTest, RayDataBackPassCreation) {
			ASSERT_NO_THROW({
				m_program->use();
			});
		}
	}
}