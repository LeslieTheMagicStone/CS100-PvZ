cmake_minimum_required(VERSION 3.16)

add_library(
  Plant
  STATIC
  Plant.hpp
  Plant.cpp
)

target_link_libraries(
  Plant
  GameObject
  GameWorld
  Projectile
  Sun
  SimpleCollisionBox
)

target_include_directories(
  Plant
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/Projectile/
  ${CMAKE_SOURCE_DIR}/src/Sun/
  ${CMAKE_SOURCE_DIR}/src/SimpleCollisionBox/
)
