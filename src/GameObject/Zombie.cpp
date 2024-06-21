#include "Zombie.hpp"
#include "GameWorld.hpp"

Zombie::Zombie(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int health, int damage, int speed, bool canEat)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_ZOMBIES, 20, 80, animID, CollisionCheckTag::ZOMBIE),
      m_health(health), m_damage(damage), m_speed(speed), m_isEating(false), m_canEat(canEat), m_isMovable(true) {}

void Zombie::Update()
{
    if (GetDead())
        return;

    if (m_isMovable)
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
    if (!m_isEating && m_canEat && value)
    {
        PlayAnimation(ANIMID_EAT_ANIM);
        m_isEating = true;
        m_isMovable = false;
    }
    else if (m_isEating && !value)
    {
        PlayAnimation(ANIMID_WALK_ANIM);
        m_isEating = false;
        m_isMovable = true;
    }
}

void Zombie::SetSpeed(int value) { m_speed = value; }

void Zombie::SetMovable(bool value) { m_isMovable = value; }

void Zombie::SetCanEat(bool value) { m_canEat = value; }

RegularZombie::RegularZombie(pGameWorld _pGameWorld, int x, int y)
    : Zombie(_pGameWorld, IMGID_REGULAR_ZOMBIE, x, y, ANIMID_WALK_ANIM, 200, 3, 1, true) {}

BucketHeadZombie::BucketHeadZombie(pGameWorld _pGameWorld, int x, int y)
    : Zombie(_pGameWorld, IMGID_BUCKET_HEAD_ZOMBIE, x, y, ANIMID_WALK_ANIM, 1100, 3, 1, true), m_hasBucket(true) {}

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
    : Zombie(_pGameWorld, IMGID_POLE_VAULTING_ZOMBIE, x, y, ANIMID_RUN_ANIM, 340, 3, 2, false),
      m_hasPole(true), m_isJumping(false), m_jumpAnimTimerTicks(0) {}

void PoleVaultingZombie::Update()
{
    if (GetDead())
        return;

    if (m_isJumping)
    {
        m_jumpAnimTimerTicks--;
        if (m_jumpAnimTimerTicks == 0)
            Land();
        return;
    }

    if (m_hasPole)
    {
        MoveTo(GetX() - 40, GetY());
        if (m_pGameWorld->CheckEatablePlantCollision(shared_from_this()))
            Jump();
        MoveTo(GetX() + 40, GetY());
    }

    Zombie::Update();
}

void PoleVaultingZombie::Jump()
{
    m_isJumping = true;
    m_hasPole = false;

    m_jumpAnimTimerTicks = 42;

    PlayAnimation(ANIMID_JUMP_ANIM);
    SetMovable(false);
}

void PoleVaultingZombie::Land()
{
    m_isJumping = false;

    MoveTo(GetX() - 150, GetY());

    PlayAnimation(ANIMID_WALK_ANIM);
    SetSpeed(1);
    SetCanEat(true);
    SetMovable(true);
}