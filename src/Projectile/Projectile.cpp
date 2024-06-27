#include "Projectile.hpp"

Projectile::Projectile(pGameWorld _pGameWorld, ImageID imageID, int x, int y, int width, int height, AnimID animID, int damage)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_PROJECTILES, width, height, animID, CollisionCheckTag::PROJECTILE), m_damage(damage) {}

void Projectile::OnClick() {}

int Projectile::GetDamage() const
{
    return m_damage;
}

Pea::Pea(pGameWorld _pGameWorld, int x, int y)
    : Projectile(_pGameWorld, IMGID_PEA, x, y, 28, 28, ANIMID_NO_ANIMATION, 20) {}

void Pea::Update()
{
    if (GetDead())
        return;
    MoveTo(GetX() + 8, GetY());
    if (GetX() > WINDOW_WIDTH)
        Destroy();
}

void Pea::OnCollision()
{
    Destroy();
}

Explosion::Explosion(pGameWorld _pGameWorld, int x, int y)
    : Projectile(_pGameWorld, IMGID_EXPLOSION, x, y, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION, 999), m_lifeTimeTicks(3) {}

void Explosion::Update()
{
    if (m_lifeTimeTicks == 0)
        Destroy();
    else
        m_lifeTimeTicks--;
}

void Explosion::OnCollision() {}
