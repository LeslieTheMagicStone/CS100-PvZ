#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

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
  bool CheckEatablePlantCollision(pConstGameObject gameObject) const;

private:
  pGameWorld m_instance;
  std::list<std::shared_ptr<GameObject>> m_gameObjects;
  long long m_timeTicks;
  int m_sun;
  int m_wave;
  std::shared_ptr<TextBase> m_sunText;
  std::shared_ptr<TextBase> m_waveText;
  std::shared_ptr<TextBase> m_wavesSurvivedText;
  ActionType m_selectedActionType;
  int m_waveTimerTicks;
  std::list<std::shared_ptr<EatablePlant>> m_eatablePlants;
  std::list<std::shared_ptr<Zombie>> m_zombies;
  std::list<std::shared_ptr<Projectile>> m_projectiles;
};

#endif // !GAMEWORLD_HPP__
