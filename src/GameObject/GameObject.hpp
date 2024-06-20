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

#endif // !GAMEOBJECT_HPP__
