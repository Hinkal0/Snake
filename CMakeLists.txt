cmake_minimum_required(VERSION 3.11)

project(Snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RUNTIME_DIR "${CMAKE_BINARY_DIR}/bin")

include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG 0fa201c969e48ecc253581c5841ce73f44d42f49
)

FetchContent_MakeAvailable(SFML)

add_custom_target(textures
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/textures
    ${RUNTIME_DIR}/textures
)

add_custom_target(fonts
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/fonts
    ${RUNTIME_DIR}/fonts
)

add_executable(snake
  entry.cpp
  Field.cpp
  GameManager.cpp
  Snake.cpp
  Text.cpp
)

set_target_properties(snake 
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_DIR}
)

if (WIN32)
  target_link_options(snake PRIVATE -mwindows)
endif()

target_link_libraries(snake
  PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

add_dependencies(snake textures fonts)