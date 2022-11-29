cmake_minimum_required(VERSION 3.21)
project(LIFEAA)

set(CMAKE_CXX_STANDARD 14)

add_executable(LIFEAA main.cpp Cell.h Grid.h Config_Import.h SFML_export.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(LIFEAA sfml-system sfml-window sfml-graphics sfml-audio)
