cmake_minimum_required (VERSION 2.6)
project (Fluid_Simulator)

# Dlls dir.
set (ENGINE_DLL_WIN64_DIR ${ENGINE_DLL_WIN64_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/bin/Win64")

# Copy dlls as post build process to a target.
macro (install_dlls dll_dir target)
  add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${dll_dir}
        $<TARGET_FILE_DIR:${target}>)
endmacro (install_dlls)

# Engine include directories.
set (ENGINE_HEADER_DIR ${ENGINE_HEADER_DIR} "${PROJECT_SOURCE_DIR}/engine/source/headers")
set (ENGINE_INCLUDE_DIR ${ENGINE_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/include")
set (ENGINE_INCLUDE_DIR ${ENGINE_INCLUDE_DIR} "${ENGINE_HEADER_DIR}")

add_subdirectory (engine)
add_subdirectory (simulator)
add_subdirectory (tests)