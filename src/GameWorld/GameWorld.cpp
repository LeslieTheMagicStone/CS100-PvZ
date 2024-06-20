#include "GameWorld.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  // Add a background.
  m_gameObjects.push_back(std::make_shared<Background>());
  // Add planting spots.
  for (int row = 0; row < GAME_ROWS; row++)
    for (int col = 0; col < GAME_COLS; col++)
      m_gameObjects.push_back(
          std::make_shared<PlantingSpot>(shared_from_this(), FIRST_COL_CENTER + col * LAWN_GRID_WIDTH, FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT));
}

LevelStatus GameWorld::Update()
{
  // YOUR CODE HERE
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  // YOUR CODE HERE
}

void GameWorld::Instantiate(std::shared_ptr<GameObject> gameObject)
{
  m_gameObjects.push_back(gameObject);
}
