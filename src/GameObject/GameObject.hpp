#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);

private:
};

class Background : public GameObject
{
public:
  Background();
  void Update() override;
  void OnClick() override;
};

class PlantingSpot : public GameObject
{
private:
  pGameWorld m_gameWorld;

public:
  PlantingSpot(pGameWorld gameWorld, int x, int y);
  void Update() override;
  void OnClick() override;
};

class Plant : public GameObject
{
public:
  Plant() = delete;
  Plant(ImageID imageID, int x, int y, AnimID animID);
};

class SunFlower : public Plant
{
public:
  SunFlower(int x, int y);
  void Update() override;
  void OnClick() override;
};

#endif // !GAMEOBJECT_HPP__
