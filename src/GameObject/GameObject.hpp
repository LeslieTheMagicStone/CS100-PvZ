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

  void Destroy();

  bool GetDead() const;

private:
  bool m_isDead;
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

class Sun : public GameObject
{
public:
  Sun(pGameWorld gameWorld, int x, int y, int lifeTimeTicks);
  void Update() override;
  void OnClick() override;

protected:
  bool m_isGrounded;

private:
  pGameWorld m_gameWorld;
  int m_lifeTimeTicks;
  int m_groundedTicks;
};

class NaturalSun : public Sun
{
public:
  NaturalSun(pGameWorld gameWorld, int x, int y);
  void Update() override;
};

#endif // !GAMEOBJECT_HPP__
