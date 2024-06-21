#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

#include "ActionType.hpp"
#include "CollisionCheckTag.hpp"

class Zombie;
class EatablePlant;
class Projectile;

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  void AddToGameObjects(std::shared_ptr<GameObject> gameObject);

  void UpdateSun(int delta);

  bool TryCostSun(int cost);

  ActionType GetSelectedActionType() const;
  void SetSelectedActionType(ActionType actionType);

  bool CheckZombieCollision(pConstGameObject gameObject) const;

private:
  pGameWorld m_instance;
  std::list<std::shared_ptr<GameObject>> m_gameObjects;
  long long m_timeTicks;
  int m_sun;
  int m_wave;
  TextBase m_sunText = TextBase(61, WINDOW_HEIGHT - 80, "", 0.3, 0.3, 0.4, true);
  TextBase m_waveText = TextBase(WINDOW_WIDTH - 130, 5, "", 0.2, 0.2, 0.3, false);
  ActionType m_selectedActionType;
  int m_waveTimerTicks;
  std::list<std::shared_ptr<EatablePlant>> m_eatablePlants;
  std::list<std::shared_ptr<Zombie>> m_zombies;
  std::list<std::shared_ptr<Projectile>> m_projectiles;
  TextBase m_wavesSurvivedText = TextBase(WINDOW_WIDTH / 2 - 67, 50, "", 1, 1, 1, true);
};

#endif // !GAMEWORLD_HPP__
