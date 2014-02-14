# Set include dirs.
include_directories (${ENGINE_INCLUDE_DIR})

# Use new policy in link_directories(): output absolute paths.
cmake_policy(SET CMP0015 NEW)

# Set source directories.
set (CPP_DIR ${CPP_DIR} "source/src")

# Add the executable
add_library (Fluid_Engine
	${ENGINE_HEADER_DIR}/Application.h	${CPP_DIR}/Application.cpp
	${ENGINE_HEADER_DIR}/Program.h		${CPP_DIR}/Program.cpp
	${ENGINE_HEADER_DIR}/Fluid2D.h		${CPP_DIR}/Fluid2D.cpp)
	
# Add libraries.
# TODO: set options for platform and build type.
set (LIBS_WIN64_DIR ${LIBS_WIN64_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/lib/Win64")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/freeglut.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/cg.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/cgGL.lib")

cmake_policy(SET CMP0015 NEW) # Use new policy in link_directories(): output absolute paths.
target_link_libraries (Fluid_Engine ${LIBS_DIR})
		
# Install target.
install (TARGETS Fluid_Engine DESTINATION ${PROJECT_BINARY_DIR}/engine)