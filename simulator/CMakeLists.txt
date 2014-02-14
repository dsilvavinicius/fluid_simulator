# Set include dirs.
include_directories (${ENGINE_INCLUDE_DIR})

# Set source directories.
set (CPP_DIR ${CPP_DIR} "cpp")

# Add the executable
add_executable (Fluid_Simulator
	${CPP_DIR}/main.cpp)

target_link_libraries (Fluid_Simulator Fluid_Engine)

install_dlls (Fluid_Simulator)

# add the install targets
install (TARGETS Fluid_Simulator DESTINATION ${PROJECT_BINARY_DIR}/simulator)