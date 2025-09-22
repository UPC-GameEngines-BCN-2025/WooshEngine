# CMakeList.txt : CMake project for GameEngineTemplate, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)          # request C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # require it
set(CMAKE_CXX_EXTENSIONS OFF)       # optional: disable compiler-specific extensions
set(CMAKE_ANDROID_RTTI OFF)			# disable RTTI

project (WooshEngine)

find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Add source to this project's executable.
add_executable (WooshEngine "src/WooshEngine.cpp" "src/WooshEngine.h")

target_link_libraries(WooshEngine PRIVATE glm::glm)
target_link_libraries(WooshEngine PRIVATE glad::glad)
target_link_libraries(WooshEngine PRIVATE SDL3::SDL3)
target_link_libraries(WooshEngine PRIVATE OpenGL::GL)
