##############################
# Root build description.
# Path: ./
##############################

cmake_minimum_required (VERSION 2.6)
project (Fluid_Simulator)

# Dlls dir.
set (ENGINE_DLL_WIN64_DIR ${ENGINE_DLL_WIN64_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/bin/Win64")

# Copies all dlls in dll_dir to target.
macro (install_dlls dll_dir target)
	add_custom_command(TARGET ${target} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			${dll_dir}
			$<TARGET_FILE_DIR:${target}>)
endmacro (install_dlls)

# Creates the file groups and setups file directory related variables. Should be used on engine and
# tests subtrees so both IDE projects will have the same file hierarchy. 
macro (create_file_groups headers_dir cpp_dir)
	set (INFRA_PACK_CPP_DIR ${cpp_dir}/infrastructure)
	set (INFRA_PACK_HEADER_DIR ${headers_dir}/infrastructure)

	set (ENGINE_PACK_CPP_DIR ${cpp_dir}/engine)
	set (ENGINE_PACK_HEADER_DIR ${headers_dir}/engine)

	set (OGL_PACK_CPP_DIR ${cpp_dir}/ogl)
	set (OGL_PACK_HEADER_DIR ${headers_dir}/ogl)

	set (SHADER_DIR ${SHADER_DIR} ${cpp_dir}/shaders)

	# Specifying sources.
	file (GLOB_RECURSE ENGINE_SRCS ${ENGINE_PACK_HEADER_DIR}/*.h
		${ENGINE_PACK_CPP_DIR}/*.cpp)
	file (GLOB_RECURSE INFRASTRUCTURE_SRCS ${INFRA_PACK_HEADER_DIR}/*.h
		${INFRA_PACK_CPP_DIR}/*.cpp)
	file (GLOB_RECURSE OGL_SRCS ${OGL_PACK_HEADER_DIR}/*.h
		${OGL_PACK_CPP_DIR}/*.cpp)
	file (GLOB_RECURSE SHADERS_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/source/src/shaders/*.vert
		${CMAKE_CURRENT_SOURCE_DIR}/source/src/shaders/*.frag
	)

	# Creating source groups.
	source_group (engine FILES ${ENGINE_SRCS})
	source_group (infrastructure FILES ${INFRASTRUCTURE_SRCS})
	source_group (ogl FILES ${OGL_SRCS})
	source_group (shaders FILES ${SHADERS_SRCS})
endmacro (create_file_groups)

# Engine include directories.
set (ENGINE_HEADER_DIR ${ENGINE_HEADER_DIR} "${PROJECT_SOURCE_DIR}/engine/source/headers")
set (ENGINE_INCLUDE_DIR ${ENGINE_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/include")
set (ENGINE_INCLUDE_DIR ${ENGINE_INCLUDE_DIR} "${ENGINE_HEADER_DIR}")

add_subdirectory (engine)
add_subdirectory (simulator)
add_subdirectory (tests)