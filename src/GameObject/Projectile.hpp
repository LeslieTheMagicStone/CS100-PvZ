#ifndef PROJECTILE_HPP__
#define PROJECTILE_HPP__

#include "GameObject.hpp"

class Projectile : public GameObject
{
public:
    Projectile(pGameWorld _pGameWorld, ImageID imageID, int x, int y, int width, int height, AnimID animID, int damage);

    void OnClick() override;

    int GetDamage() const;

    virtual void OnCollision() = 0;

private:
    int m_damage;
};

class Pea : public Projectile
{
public:
    Pea(pGameWorld _pGameWorld, int x, int y);

    void Update() override;
    void OnCollision() override;
};

class Explosion : public Projectile
{
public:
    Explosion(pGameWorld _pGameWorld, int x, int y);

    void Update() override;
    void OnCollision() override;

private:
    int m_lifeTimeTicks;
};

#endif // !PROJECTILE_HPP__