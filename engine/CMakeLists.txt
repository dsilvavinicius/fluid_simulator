##############################
# Engine build description.
# Path: engine/
##############################

# Set include dirs.
include_directories (${ENGINE_INCLUDE_DIR})

# Set source directories.
set (CPP_DIR "source/src")

# Creates file groups for IDE and setups source directory related variables.
create_file_groups (${ENGINE_HEADER_DIR} ${CPP_DIR})

# Creating the library.
add_library (Fluid_Engine
	${INFRA_PACK_HEADER_DIR}/Application.h		${INFRA_PACK_CPP_DIR}/Application.cpp
	${INFRA_PACK_HEADER_DIR}/Utils.h			${INFRA_PACK_CPP_DIR}/Utils.cpp
	
	${ENGINE_PACK_HEADER_DIR}/Program.h			${ENGINE_PACK_CPP_DIR}/Program.cpp
	${ENGINE_PACK_HEADER_DIR}/Fluid3D.h			${ENGINE_PACK_CPP_DIR}/Fluid3D.cpp
	${ENGINE_PACK_HEADER_DIR}/Boundary.h		${ENGINE_PACK_CPP_DIR}/Boundary.cpp
	${ENGINE_PACK_HEADER_DIR}/RayData.h			${ENGINE_PACK_CPP_DIR}/RayData.cpp
	${ENGINE_PACK_HEADER_DIR}/RayDataBackPass.h	${ENGINE_PACK_CPP_DIR}/RayDataBackPass.cpp
	${ENGINE_PACK_HEADER_DIR}/DisplaySettings.h	${ENGINE_PACK_CPP_DIR}/DisplaySettings.cpp
	
	${OGL_PACK_HEADER_DIR}/OGL.h				${OGL_PACK_CPP_DIR}/OGL.cpp
	${OGL_PACK_HEADER_DIR}/Buffer.h				${OGL_PACK_CPP_DIR}/Buffer.cpp
	${OGL_PACK_HEADER_DIR}/UniformBuffer.h		${OGL_PACK_CPP_DIR}/UniformBuffer.cpp
	${OGL_PACK_HEADER_DIR}/UniformBlock.h		${OGL_PACK_CPP_DIR}/UniformBlock.cpp
	
	# Shaders
	${SHADER_DIR}/RayDataBackPass.vert			${SHADER_DIR}/RayDataBackPass.frag)
	
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