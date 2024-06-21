#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

#include "ActionType.hpp"

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

private:
  pGameWorld m_instance;
  std::list<std::shared_ptr<GameObject>> m_gameObjects;
  long long m_timeTicks;
  int m_sun;
  int m_wave;
  TextBase m_sunText = TextBase(61, WINDOW_HEIGHT - 80, "0", 0.3, 0.3, 0.4, true);
  TextBase m_waveText = TextBase(WINDOW_WIDTH - 130, 5, "Wave: 0", 0.2, 0.2, 0.3, false);
  ActionType m_selectedActionType;
};

#endif // !GAMEWORLD_HPP__
