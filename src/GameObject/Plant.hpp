#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "GameObject.hpp"

class Plant : public GameObject
{
public:
    Plant() = delete;
    Plant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, CollisionCheckTag collisionCheckTag = CollisionCheckTag::NONE);

    void OnClick() override;
};

class EatablePlant : public Plant
{
public:
    EatablePlant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int maxHealth);

    int GetMaxHealth() const;
    int GetHealth() const;
    void TakeDamage(int damage);

private:
    int m_maxHealth;
    int m_health;
};

class Sunflower : public EatablePlant
{
public:
    Sunflower(pGameWorld _pGameWorld, int x, int y);
    void Update() override;

private:
    int m_sunTimerTicks;
};

class Shooter : public EatablePlant
{
public:
    Shooter(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int maxHealth, int shootIntervalTicks);

    void OnDestroy() override;

    bool GetHasTarget();

private:
    pGameObject m_pShootRangeIndicator;
};

class Peashooter : public Shooter
{
public:
    Peashooter(pGameWorld _pGameWorld, int x, int y);

    void Update() override;

private:
    int m_shootTimerTicks;
};

class Wallnut : public EatablePlant
{
public:
    Wallnut(pGameWorld _pGameWorld, int x, int y);

    void Update() override;
};

class CherryBomb : public Plant
{
public:
    CherryBomb(pGameWorld _pGameWorld, int x, int y);

    void Update() override;

private:
    int m_timerTicks;
};

class Repeater : public Shooter
{
public:
    Repeater(pGameWorld _pGameWorld, int x, int y);

    void Update() override;

private:
    int m_shootTimerTicks;
    int m_remainingShots;
    int m_continuousShootTimerTicks;

    void ShootPea();
};

#endif // !PLANT_HPP__