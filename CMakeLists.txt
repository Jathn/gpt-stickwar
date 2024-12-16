cmake_minimum_required(VERSION 3.10)
project(StickWar)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB SOURCES "src/*.cpp")
add_executable(StickWar ${SOURCES})

# Include directories
target_include_directories(StickWar PUBLIC include)

# Link SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(StickWar sfml-graphics sfml-window sfml-system)
