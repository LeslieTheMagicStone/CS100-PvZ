#include "GameObject.hpp"
#include "GameWorld.hpp"

// Your everything begins from here.
GameObject::GameObject(const ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID), m_isDead(false) {}

void GameObject::Destroy() { m_isDead = true; }

bool GameObject::GetDead() const { return m_isDead; }

Generator::Generator(pGameWorld gameWorld, const ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld) {}
void Generator::Instantiate(std::shared_ptr<GameObject> gameObject) { m_gameWorld->AddToGameObjects(gameObject); }

