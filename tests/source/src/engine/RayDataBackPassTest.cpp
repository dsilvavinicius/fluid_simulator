#include <gtest/gtest.h>
#include <glm/glm.hpp>

#include "infrastructure/Application.h"
#include "engine/RayDataBackPass.h"

using namespace glm;
using namespace infrastructure;
using namespace engine;

class RayDataBackPassTest : public testing::Test
{
protected:
	RayDataBackPassTest() {}

	virtual ~RayDataBackPassTest() {}

	virtual void SetUp(){
		Application& app = Application::getInstance();
		app.createMainWindow();
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