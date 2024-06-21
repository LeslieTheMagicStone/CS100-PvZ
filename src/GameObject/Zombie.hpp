#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include "GameObject.hpp"

class Zombie : public GameObject
{

public:
    Zombie() = delete;
    Zombie(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int health, int damage, int speed);

    void Update() override;
    void OnClick() override;

    int GetHealth() const;
    void TakeDamage(int damage);

    int GetDamage() const;

    void SetEating(bool value);

private:
    int m_health;
    int m_damage;
    int m_speed;
    bool m_isEating;
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
};

class PoleVaultingZombie : public Zombie
{
public:
    PoleVaultingZombie(pGameWorld _pGameWorld, int x, int y);
};

#endif // !ZOMBIE_HPP__