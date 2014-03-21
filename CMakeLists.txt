##############################
# Root build description.
# Path: ./
##############################

cmake_minimum_required (VERSION 2.6)
project (Fluid_Simulator)

# Dlls dir.
set (ENGINE_DLL_WIN64_DIR ${ENGINE_DLL_WIN64_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/bin/Win64")

# Copies all files in dir to target at a specific time (PRE_BUILD or POST_BUILD).
macro (install_dir dir target time)
	add_custom_command(TARGET ${target} ${time}
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			${dll}
			$<TARGET_FILE_DIR:${target}>)
endmacro (install_dir)

# Copies all dlls in dll_dir to target.
macro (install_dlls dll_dir target)
	install_dir(dll_dir target POST_BUILD)
endmacro (install_dlls)

# Engine include directories.
set (ENGINE_HEADER_DIR ${ENGINE_HEADER_DIR} "${PROJECT_SOURCE_DIR}/engine/source/headers")
set (ENGINE_INCLUDE_DIR ${ENGINE_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/include")
set (ENGINE_INCLUDE_DIR ${ENGINE_INCLUDE_DIR} "${ENGINE_HEADER_DIR}")

add_subdirectory (engine)
add_subdirectory (simulator)
add_subdirectory (tests)