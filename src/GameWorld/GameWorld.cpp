#include "GameWorld.hpp"
#include "Background.hpp"
#include "Sun.hpp"
#include "PlantingSpot.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  // Init time.
  m_timeTicks = 0;
  // Init sun.
  m_sun = 50;
  // Init wave.
  m_wave = 0;
  // Init selected seed.
  m_selectedSeedType = SeedType::NONE;
  // Add a background.
  m_gameObjects.push_back(std::make_shared<Background>(shared_from_this()));
  // Add planting spots.
  for (int row = 0; row < GAME_ROWS; row++)
    for (int col = 0; col < GAME_COLS; col++)
      m_gameObjects.push_back(
          std::make_shared<PlantingSpot>(shared_from_this(), FIRST_COL_CENTER + col * LAWN_GRID_WIDTH, FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT));
  // Add seed selection buttons.
  m_gameObjects.push_back(std::make_shared<SunflowerSeed>(shared_from_this(), 130, WINDOW_HEIGHT - 44));
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

  // 5. Check for collisions.
  for (auto damager : m_damagers)
    for (auto damageable : m_damageables)
      if (damager->GetIsEnemy() != damageable->GetIsEnemy() && damager->CheckColliding(damageable))
        damager->OnCollision(damageable);

  // 6. Remove dead game objects.
  m_gameObjects.remove_if([](auto gameObject)
                          { return gameObject->GetDead(); });

  // 9. Update text UIs.
  m_sunText.SetText(std::to_string(m_sun));
  m_waveText.SetText("Wave: " + std::to_string(m_wave));

  // 10. Return the level status.
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp()
{
  m_selectedSeedType = SeedType::NONE;
  m_gameObjects.clear();
}

void GameWorld::AddToGameObjects(std::shared_ptr<GameObject> gameObject)
{
  m_gameObjects.push_back(gameObject);
}

void GameWorld::UpdateSun(int deltaValue)
{
  m_sun += deltaValue;
}

bool GameWorld::TryCostSun(int cost)
{
  if (cost <= m_sun)
  {
    UpdateSun(-cost);
    return true;
  }
  return false;
}

SeedType GameWorld::GetSelectedSeedType() const
{
  return m_selectedSeedType;
}

void GameWorld::SetSelectedSeedType(SeedType seedType)
{
  m_selectedSeedType = seedType;
}
