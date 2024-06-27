#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include "GameObject.hpp"

class Zombie : public GameObject
{

public:
    Zombie() = delete;
    Zombie(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int health, int damage, int speed, bool canEat);

    void Update() override;
    void OnClick() override;

    int GetHealth() const;
    void TakeDamage(int damage);

    int GetDamage() const;

    void SetEating(bool value);

    void SetSpeed(int value);
    void SetMovable(bool value);
    void SetCanEat(bool value);

private:
    int m_health;
    int m_damage;
    int m_speed;
    bool m_isEating;
    bool m_canEat;
    bool m_isMovable;
    AnimID m_moveAnim;
};

class RegularZombie : public Zombie
{
public:
    RegularZombie(pGameWorld _pGameWorld, int x, int y);
};

class BucketHeadZombie : public Zombie
{
public:
    BucketHeadZombie(pGameWorld _pGameWorld, int x, int y);

    void Update() override;

private:
    bool m_hasBucket;
};

class PoleVaultingZombie : public Zombie
{
public:
    PoleVaultingZombie(pGameWorld _pGameWorld, int x, int y);

    void Update() override;

private:
    bool m_hasPole;
    bool m_isJumping;
    int m_jumpAnimTimerTicks;

    void Jump();
    void Land();
};

#endif // !ZOMBIE_HPP__