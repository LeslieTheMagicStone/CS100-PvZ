#include "GameObject.hpp"
#include "GameWorld.hpp"

// Your everything begins from here.
GameObject::GameObject(pGameWorld _pGameWorld, ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, CollisionCheckTag collisionCheckTag)
    : ObjectBase(imageID, x, y, layer, width, height, animID), m_pGameWorld(_pGameWorld), m_isDead(false), m_collisionCheckTag(collisionCheckTag) {}

void GameObject::Destroy()
{
    OnDestroy();
    m_isDead = true;
}

bool GameObject::GetDead() const { return m_isDead; }

void GameObject::Instantiate(pGameObject gameObject) { m_pGameWorld->AddToGameObjects(gameObject); }

bool GameObject::CheckCollision(pConstGameObject other) const
{
    if (other == shared_from_this())
        return false;
    if (GetDead())
        return false;
    bool collidingX = std::abs(GetX() - other->GetX()) < GetWidth() / 2 + other->GetWidth() / 2;
    bool collidingY = std::abs(GetY() - other->GetY()) < GetHeight() / 2 + other->GetHeight() / 2;
    return collidingX && collidingY;
}

CollisionCheckTag GameObject::GetCollisionCheckTag() const { return m_collisionCheckTag; }

void GameObject::OnDestroy() {}
