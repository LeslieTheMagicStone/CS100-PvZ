#include "Zombie.hpp"

Zombie::Zombie(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int health, int damage, int speed)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_ZOMBIES, 20, 80, animID, CollisionCheckTag::ZOMBIE), m_health(health), m_damage(damage), m_speed(speed), m_isEating(false), m_moveAnim(animID) {}

void Zombie::Update()
{
    if (GetDead())
        return;

    if (!m_isEating)
    {
        MoveTo(GetX() - m_speed, GetY());
    }
}

void Zombie::OnClick() {}

int Zombie::GetHealth() const { return m_health; }

void Zombie::TakeDamage(int damage)
{
    if (GetDead())
        return;

    if (m_health > damage)
        m_health -= damage;
    else
        m_health = 0;

    if (m_health == 0)
        Destroy();
}

int Zombie::GetDamage() const { return m_damage; }

void Zombie::SetEating(bool value)
{
    if (!m_isEating && value)
    {
        PlayAnimation(ANIMID_EAT_ANIM);
        m_isEating = true;
    }
    else if (m_isEating && !value)
    {
        PlayAnimation(m_moveAnim);
        m_isEating = false;
    }
}

RegularZombie::RegularZombie(pGameWorld _pGameWorld, int x, int y)
    : Zombie(_pGameWorld, IMGID_REGULAR_ZOMBIE, x, y, ANIMID_WALK_ANIM, 200, 3, 1) {}

BucketHeadZombie::BucketHeadZombie(pGameWorld _pGameWorld, int x, int y)
    : Zombie(_pGameWorld, IMGID_BUCKET_HEAD_ZOMBIE, x, y, ANIMID_WALK_ANIM, 1100, 3, 1), m_hasBucket(true) {}

void BucketHeadZombie::Update()
{
    if (GetDead())
        return;

    Zombie::Update();

    if (m_hasBucket && GetHealth() < 200)
    {
        m_hasBucket = false;
        ChangeImage(IMGID_REGULAR_ZOMBIE);
    }
}

PoleVaultingZombie::PoleVaultingZombie(pGameWorld _pGameWorld, int x, int y)
    : Zombie(_pGameWorld, IMGID_POLE_VAULTING_ZOMBIE, x, y, ANIMID_RUN_ANIM, 340, 3, 2) {}