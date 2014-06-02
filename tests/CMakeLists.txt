##############################
# Tests build description.
# Path: tests/
##############################

# Set include dirs.
set (TEST_INCLUDE_DIR ${TEST_INCLUDE_DIR} "libraries/include")

include_directories (${ENGINE_INCLUDE_DIR})
include_directories (${TEST_INCLUDE_DIR})

# Creates file groups for IDE and setups source directory related variables.
set (HEADER_DIR ${HEADER_DIR} "source/headers")
set (CPP_DIR ${CPP_DIR} "source/src")
create_file_groups (${HEADER_DIR} ${CPP_DIR})

# Bug fix. Since engine and tests has the same directoty structure, the test headers aren't
# visible in test cpps (they are being overwriten by engine directories). The line below fixes it.
include_directories (${HEADER_DIR})

# Adds the executable
add_executable (Tests
	${CPP_DIR}/main.cpp
	
	${INFRA_PACK_HEADER_DIR}/Test.h				${INFRA_PACK_CPP_DIR}/Test.cpp
	${OGL_PACK_HEADER_DIR}/UniformBlockTest.h	${OGL_PACK_CPP_DIR}/UniformBlockTest.cpp)

set (LIBS_WIN64_DIR ${LIBS_WIN64_DIR} "${PROJECT_SOURCE_DIR}/tests/libraries/lib/Win64")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/gtest.lib")

target_link_libraries (Tests ${LIBS_DIR})
target_link_libraries (Tests Fluid_Engine)

# Engine dlls.
install_dlls (${ENGINE_DLL_WIN64_DIR} Tests)
# gTest dlls.
set (GTEST_DLL_DIR ${GTEST_DLL_DIR} "${PROJECT_SOURCE_DIR}/tests/libraries/bin")
install_dlls (${GTEST_DLL_DIR} Tests)

# add the install targets
install (TARGETS Tests DESTINATION ${PROJECT_BINARY_DIR}/tests)