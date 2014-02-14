# Set include dirs.
set (TEST_INCLUDE_DIR ${TEST_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/tests/libraries/include")

include_directories (${ENGINE_INCLUDE_DIR})
include_directories (${TEST_INCLUDE_DIR})

# Set source directories.
set (CPP_DIR ${CPP_DIR} "cpp")

# Add the executable
add_executable (Tests
	${CPP_DIR}/main.cpp)

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