#include "GameWorld.hpp"
#include "Background.hpp"
#include "Sun.hpp"
#include "PlantingSpot.hpp"
#include "Shovel.hpp"
#include "Zombie.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init()
{
  // Init time.
  m_timeTicks = 0;
  // Init sun.
  m_sun = 500;
  // Init wave.
  m_wave = 0;
  // Init wave timer.
  m_waveTimerTicks = 1200;
  // Init selected seed.
  m_selectedActionType = ActionType::NONE;
  // Add a background.
  m_gameObjects.push_back(std::make_shared<Background>(shared_from_this()));
  // Add planting spots.
  for (int row = 0; row < GAME_ROWS; row++)
    for (int col = 0; col < GAME_COLS; col++)
      m_gameObjects.push_back(
          std::make_shared<PlantingSpot>(shared_from_this(), FIRST_COL_CENTER + col * LAWN_GRID_WIDTH, FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT));
  // Add seed selection buttons.
  m_gameObjects.push_back(std::make_shared<SunflowerSeed>(shared_from_this(), 130, WINDOW_HEIGHT - 44));
  m_gameObjects.push_back(std::make_shared<PeashooterSeed>(shared_from_this(), 190, WINDOW_HEIGHT - 44));
  m_gameObjects.push_back(std::make_shared<WallnutSeed>(shared_from_this(), 250, WINDOW_HEIGHT - 44));
  m_gameObjects.push_back(std::make_shared<CherryBombSeed>(shared_from_this(), 310, WINDOW_HEIGHT - 44));
  m_gameObjects.push_back(std::make_shared<RepeaterSeed>(shared_from_this(), 370, WINDOW_HEIGHT - 44));
  // Add shovel.
  m_gameObjects.push_back(std::make_shared<Shovel>(shared_from_this(), 600, WINDOW_HEIGHT - 40));
}

LevelStatus GameWorld::Update()
{
  // 0. Update time.
  m_timeTicks++;
  // 1. Generate natural sun.
  if (m_timeTicks % 300 == 180)
    m_gameObjects.push_back(std::make_shared<NaturalSun>(shared_from_this(), randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1));
  // 2. Determine whether to generate zombies.
  int zombieCount = 0;
  if (m_waveTimerTicks == 0)
  {
    m_wave++;
    m_waveTimerTicks = std::max(150, 600 - 20 * m_wave);
    zombieCount = (15 + m_wave) / 10;
  }
  m_waveTimerTicks--;
  // 3. Generate zombies.
  int P1 = 20;
  int P2 = 2 * std::max(m_wave - 8, 0);
  int P3 = 3 * std::max(m_wave - 15, 0);
  for (int i = 0; i < zombieCount; i++)
  {
    int randNum = randInt(1, P1 + P2 + P3);
    int randRow = randInt(0, GAME_ROWS - 1);
    int randX = randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1);
    int randY = FIRST_ROW_CENTER + randRow * LAWN_GRID_HEIGHT;
    if (randNum <= P1)
      m_gameObjects.push_back(std::make_shared<RegularZombie>(shared_from_this(), randX, randY));
    else if (randNum <= P1 + P2)
      m_gameObjects.push_back(std::make_shared<PoleVaultingZombie>(shared_from_this(), randX, randY));
    else
      m_gameObjects.push_back(std::make_shared<BucketHeadZombie>(shared_from_this(), randX, randY));
  }
  // 4. Update all game objects.
  for (auto gameObject : m_gameObjects)
    gameObject->Update();

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
  m_selectedActionType = ActionType::NONE;
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

ActionType GameWorld::GetSelectedActionType() const
{
  return m_selectedActionType;
}

void GameWorld::SetSelectedActionType(ActionType seedType)
{
  m_selectedActionType = seedType;
}
