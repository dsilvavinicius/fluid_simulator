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
	${INFRA_PACK_HEADER_DIR}/Utils.h			${INFRA_PACK_CPP_DIR}/Utils.cpp
	
	${ENGINE_PACK_HEADER_DIR}/Fluid3D.h			${ENGINE_PACK_CPP_DIR}/Fluid3D.cpp
	${ENGINE_PACK_HEADER_DIR}/Boundary.h		${ENGINE_PACK_CPP_DIR}/Boundary.cpp
	${ENGINE_PACK_HEADER_DIR}/RayData.h			${ENGINE_PACK_CPP_DIR}/RayData.cpp
	${ENGINE_PACK_HEADER_DIR}/RayDataBackPass.h	${ENGINE_PACK_CPP_DIR}/RayDataBackPass.cpp
	
	${OGL_PACK_HEADER_DIR}/OGL.h				${OGL_PACK_CPP_DIR}/OGL.cpp
	${OGL_PACK_HEADER_DIR}/Application.h		${OGL_PACK_CPP_DIR}/Application.cpp
	${OGL_PACK_HEADER_DIR}/Program.h			${OGL_PACK_CPP_DIR}/Program.cpp
	${OGL_PACK_HEADER_DIR}/ProgramInitializer.h	${OGL_PACK_CPP_DIR}/ProgramInitializer.cpp
	${OGL_PACK_HEADER_DIR}/DisplaySettings.h	${OGL_PACK_CPP_DIR}/DisplaySettings.cpp
	${OGL_PACK_HEADER_DIR}/Buffer.h				${OGL_PACK_CPP_DIR}/Buffer.cpp
	${OGL_PACK_HEADER_DIR}/Uniform.h			${OGL_PACK_CPP_DIR}/Uniform.cpp
	${OGL_PACK_HEADER_DIR}/UniformBuffer.h		${OGL_PACK_CPP_DIR}/UniformBuffer.cpp
	${OGL_PACK_HEADER_DIR}/UniformBlock.h		${OGL_PACK_CPP_DIR}/UniformBlock.cpp
	${OGL_PACK_HEADER_DIR}/FrameBuffer.h		${OGL_PACK_CPP_DIR}/FrameBuffer.cpp
	${OGL_PACK_HEADER_DIR}/RenderBuffer.h		${OGL_PACK_CPP_DIR}/RenderBuffer.cpp
	${OGL_PACK_HEADER_DIR}/ColorBuffer.h		${OGL_PACK_CPP_DIR}/ColorBuffer.cpp
	
	# Shaders
	${SHADER_DIR}/RayDataBackPass.vert			${SHADER_DIR}/RayDataBackPass.frag)
	
# Add libraries.
if (UNIX)
	set (LIBS_DIR ${LIBS_DIR} "freeglut, glew32, GL")
else (WIN32)
	set (LIBS_WIN64_DIR ${LIBS_WIN64_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/lib/Win64")
	set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/freeglut.lib")
	set (LIBS_DIR ${LIBS_DIR} "${LIBS_WIN64_DIR}/glew32.lib")
	# OpenGL32.lib is assumed to be bundled with Windows.
	set (LIBS_DIR ${LIBS_DIR} "OpenGL32.lib")
else ()
	message ("Unexpected operating system. Exiting prematurelly.")
	return ()
endif ()

cmake_policy(SET CMP0015 NEW) # Use new policy in link_directories(): output absolute paths.
target_link_libraries (Fluid_Engine ${LIBS_DIR})
		
# Install target.
install (TARGETS Fluid_Engine DESTINATION ${PROJECT_BINARY_DIR}/engine)