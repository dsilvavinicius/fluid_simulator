# Set include dirs.
set (INCLUDE_DIR ${INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/engine/libraries/include")
set (INCLUDE_DIR ${INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/engine/source/headers")
include_directories (${INCLUDE_DIR})

# Set source directories.
set (CPP_DIR ${CPP_DIR} "cpp")

# Add the executable
add_executable (Fluid_Simulator
	${CPP_DIR}/main.cpp)

cmake_policy(SET CMP0015 NEW) # Use new policy in link_directories(): output absolute paths.
target_link_libraries (Fluid_Simulator Fluid_Engine)

#set (DLL_WIN64_DIR ${DLL_WIN64_DIR} "${PROJECT_SOURCE_DIR}/libraries/bin/Win64")

#add_custom_command(TARGET Fluid_Simulator POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#        "${DLL_WIN64_DIR}"
#        $<TARGET_FILE_DIR:Fluid_Simulator>)

# add the install targets
install (TARGETS Fluid_Simulator DESTINATION ${PROJECT_BINARY_DIR}/fluid_simulator)