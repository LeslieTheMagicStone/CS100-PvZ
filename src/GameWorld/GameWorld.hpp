#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>
{
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  void Instantiate(std::shared_ptr<GameObject> gameObject);

  void Destroy(std::shared_ptr<GameObject> gameObject);

  void UpdateSun(int delta);

private:
  pGameWorld m_instance;
  std::list<std::shared_ptr<GameObject>> m_gameObjects;
  long long m_timeTicks;
  int m_sun;
};

#endif // !GAMEWORLD_HPP__
