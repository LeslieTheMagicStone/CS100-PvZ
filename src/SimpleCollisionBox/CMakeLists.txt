cmake_minimum_required(VERSION 3.16)

add_library(
  SimpleCollisionBox
  STATIC
  SimpleCollisionBox.hpp
  SimpleCollisionBox.cpp
)

target_link_libraries(
  SimpleCollisionBox
  GameObject
  GameWorld
)

target_include_directories(
  SimpleCollisionBox
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
)
