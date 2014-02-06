cmake_minimum_required (VERSION 2.6)
project (Fluid_Simulator)

# Set include dirs.
set (INCLUDE_DIR ${INCLUDE_DIR} "libraries/include")
set (HEADER_DIR ${HEADER_DIR} "source/headers")
include_directories (${INCLUDE_DIR})
include_directories (${HEADER_DIR})

# Set source directories.
set (CPP_DIR ${CPP_DIR} "source/src")

# Add the executable
add_executable (Fluid_Simulator
	${HEADER_DIR}/Application.h		${CPP_DIR}/Application.cpp
	${HEADER_DIR}/Program.h		${CPP_DIR}/Program.cpp
	${HEADER_DIR}/Fluid2D.h		${CPP_DIR}/Fluid2D.cpp
	${CPP_DIR}/main.cpp)
	
#Add libraries
# TODO: set options for platform and build type.
set (LIBS_WIN64_DIR ${LIBS_WIN64_DIR} "${PROJECT_SOURCE_DIR}/libraries/lib/Win64")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/gtest.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/freeglut.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/cg.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/cgGL.lib")

cmake_policy(SET CMP0015 NEW) # Use new policy in link_directories(): output absolute paths.
target_link_libraries (Fluid_Simulator ${LIBS_DIR})

set (DLL_WIN64_DIR ${DLL_WIN64_DIR} "${PROJECT_SOURCE_DIR}/libraries/bin/Win64")

add_custom_command(TARGET Fluid_Simulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${DLL_WIN64_DIR}"
        $<TARGET_FILE_DIR:Fluid_Simulator>)

# add the install targets
install (TARGETS Fluid_Simulator DESTINATION bin)