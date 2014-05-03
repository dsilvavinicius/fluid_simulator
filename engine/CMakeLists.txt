##############################
# Engine build description.
# Path: engine/
##############################

# Set include dirs.
include_directories (${ENGINE_INCLUDE_DIR})

# Set source directories.
set (CPP_DIR ${CPP_DIR} "source/src")
set (SHADER_DIR ${SHADER_DIR} "${CPP_DIR}/shaders")

# Add the executable
add_library (Fluid_Engine
	${ENGINE_HEADER_DIR}/Application.h		${CPP_DIR}/Application.cpp
	${ENGINE_HEADER_DIR}/Program.h			${CPP_DIR}/Program.cpp
	${ENGINE_HEADER_DIR}/Fluid3D.h			${CPP_DIR}/Fluid3D.cpp
	${ENGINE_HEADER_DIR}/Boundary.h			${CPP_DIR}/Boundary.cpp
	${ENGINE_HEADER_DIR}/RayData.h			${CPP_DIR}/RayData.cpp
	${ENGINE_HEADER_DIR}/RayDataBackPass.h	${CPP_DIR}/RayDataBackPass.cpp
	${ENGINE_HEADER_DIR}/Utils.h			${CPP_DIR}/Utils.cpp
	${ENGINE_HEADER_DIR}/OGL.h				${CPP_DIR}/OGL.cpp
	${ENGINE_HEADER_DIR}/Buffer.h			${CPP_DIR}/Buffer.cpp
	${ENGINE_HEADER_DIR}/DisplaySettings.h	${CPP_DIR}/DisplaySettings.cpp
	# Shaders
	${SHADER_DIR}/RayDataBackPass.vert		${SHADER_DIR}/RayDataBackPass.frag)
	
# Add libraries.
# TODO: set options for platform and build type.
set (LIBS_WIN64_DIR ${LIBS_WIN64_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/lib/Win64")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/freeglut.lib")
set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/glew32.lib")

cmake_policy(SET CMP0015 NEW) # Use new policy in link_directories(): output absolute paths.
target_link_libraries (Fluid_Engine ${LIBS_DIR})
# OpenGL32.lib is assumed to be bundled with Windows.
target_link_libraries (Fluid_Engine "OpenGL32.lib")
		
# Install target.
install (TARGETS Fluid_Engine DESTINATION ${PROJECT_BINARY_DIR}/engine)