cmake_minimum_required(VERSION 3.16)

add_library(
  GameObject
  STATIC
  GameObject.hpp
  GameObject.cpp
  Background.hpp
  Background.cpp
  CooldownMask.hpp
  CooldownMask.cpp
  Plant.hpp
  Plant.cpp
  PlantingSpot.hpp
  PlantingSpot.cpp
  Seed.hpp
  Seed.cpp
  SeedType.hpp
  Sun.hpp
  Sun.cpp
)

target_link_libraries(
  GameObject
  Framework
)

target_include_directories(
  GameObject
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
)
