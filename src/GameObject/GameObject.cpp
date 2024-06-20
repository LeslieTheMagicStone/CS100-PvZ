#include "GameObject.hpp"
#include "GameWorld.hpp"

// Your everything begins from here.
GameObject::GameObject(pGameWorld _pGameWorld, ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID), m_pGameWorld(_pGameWorld), m_isDead(false) {}

void GameObject::Destroy() { m_isDead = true; }

bool GameObject::GetDead() const { return m_isDead; }

void GameObject::Instantiate(std::shared_ptr<GameObject> gameObject) { m_pGameWorld->AddToGameObjects(gameObject); }
