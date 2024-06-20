#include "GameWorld.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  // Create instance
  // m_instance = shared_from_this();
  // Init time.
  m_timeTicks = 0;
  // Init sun.
  m_sun = 0;
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
  // 0. Update time.
  m_timeTicks++;
  // 1. Generate natural sun.
  if (m_timeTicks % 300 == 180)
    m_gameObjects.push_back(std::make_shared<NaturalSun>(shared_from_this(), randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1));

  // 4. Update all game objects.
  for (auto gameObject : m_gameObjects)
    gameObject->Update();

  // 6. Remove dead game objects.
  m_gameObjects.remove_if([](auto gameObject)
                          { return gameObject->GetDead(); });

  // 10. Return the level status.
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  // YOUR CODE HERE
}

void GameWorld::AddToGameObjects(std::shared_ptr<GameObject> gameObject)
{
  m_gameObjects.push_back(gameObject);
}

void GameWorld::UpdateSun(int deltaValue)
{
  m_sun += deltaValue;
}
