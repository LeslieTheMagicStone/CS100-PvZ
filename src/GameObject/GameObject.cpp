#include "GameObject.hpp"
#include "GameWorld.hpp"

// Your everything begins from here.
GameObject::GameObject(pGameWorld _pGameWorld, ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID), m_pGameWorld(_pGameWorld), m_isDead(false) {}

void GameObject::Destroy()
{
    OnDestroy();
    m_isDead = true;
}

bool GameObject::GetDead() const { return m_isDead; }

void GameObject::Instantiate(pGameObject gameObject) { m_pGameWorld->AddToGameObjects(gameObject); }

bool GameObject::CheckCollision(pGameObject other)
{
    bool collidingX = (GetX() + GetWidth() / 2 > other->GetX() - other->GetWidth() / 2) ||
                      (other->GetX() + other->GetWidth() / 2 > GetX() - GetWidth() / 2);
    bool collidingY = (GetY() + GetHeight() / 2 > other->GetY() - other->GetHeight() / 2) ||
                      (other->GetY() + other->GetHeight() / 2 > GetY() - GetHeight() / 2);
    return collidingX && collidingY;
}

void GameObject::OnDestroy() {}
