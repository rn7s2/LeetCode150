# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("LeetCode150")

include_directories("." "src/")

set(SOURCE_DIR "src/")

# Gather all the source files in the directory
file(GLOB SOURCE_FILES "${SOURCE_DIR}/*.h")

# Add source to this project's executable.
add_executable(LeetCode150 common.h main.cpp ${SOURCE_FILES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LeetCode150 PROPERTY CXX_STANDARD 20)
endif()
