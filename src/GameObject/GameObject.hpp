#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject;
using pGameObject = std::shared_ptr<GameObject>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject>
{
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

  GameObject(pGameWorld _pGameWorld, ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);

  void Destroy();

  bool GetDead() const;

  void Instantiate(pGameObject gameObject);

  bool CheckCollision(pGameObject other);

protected:
  pGameWorld m_pGameWorld;

private:
  bool m_isDead;
};

#endif // !GAMEOBJECT_HPP__
