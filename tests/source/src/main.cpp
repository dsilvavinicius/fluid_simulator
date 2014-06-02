#include <gtest/gtest.h>
#include "engine/RayDataBackPass.h"
#include "ogl/OGL.h"
#include "infrastructure/Application.h"

using namespace engine;
using namespace ogl;
using namespace infrastructure;

TEST(RayDataBackPassTest, Creation) {
	ASSERT_NO_THROW( {
		try {
			Application& app = Application::getInstance();
			app.createMainWindow();
			RayDataBackPass(mat4(1.f), mat4(1.f), vec3(0.f));
		} catch (const exception& e) {
			cerr << "Exception: " << e.what() << endl;
			rethrow_exception();
		}
	} );
	ASSERT_NO_THROW(OGL::checkError());
}


#include "ogl/UniformBlockTest.cpp"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}