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

class Generator : public GameObject
{
public:
  Generator(pGameWorld gameWorld, ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);

  void Instantiate(std::shared_ptr<GameObject> gameObject);

protected:
  pGameWorld m_gameWorld;
};

class Background : public GameObject
{
public:
  Background();
  void Update() override;
  void OnClick() override;
};

class PlantingSpot : public Generator
{
public:
  PlantingSpot(pGameWorld gameWorld, int x, int y);
  void Update() override;
  void OnClick() override;
};

class Plant : public Generator
{
public:
  Plant() = delete;
  Plant(pGameWorld gameWorld, ImageID imageID, int x, int y, AnimID animID);
};

class Sunflower : public Plant
{
public:
  Sunflower(pGameWorld gameWorld, int x, int y);
  void Update() override;
  void OnClick() override;

private:
  int sunTimerTicks;
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

class GeneratedSun : public Sun
{
public:
  GeneratedSun(pGameWorld gameWorld, int x, int y);
  void Update() override;

private:
  int m_ySpeed;
};

enum class SeedType
{
  NONE,
  SUNFLOWER,
  PEASHOOTER,
};

class Seed : public Generator
{
public:
  Seed(pGameWorld gameWorld, ImageID imageID, int x, int y, SeedType seedType, int cost);
  void Update() override;
  void OnClick() override;

private:
  SeedType m_seedType;
  int m_cost;
};

class SunflowerSeed : public Seed
{
public:
  SunflowerSeed(pGameWorld gameWorld, int x, int y);
};

#endif // !GAMEOBJECT_HPP__
