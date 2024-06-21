#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "GameObject.hpp"

class Plant : public GameObject
{
public:
    Plant() = delete;
    Plant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID);

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

class Peashooter : public EatablePlant
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

class Repeater : public EatablePlant
{
public:
    Repeater(pGameWorld _pGameWorld, int x, int y);
    void Update() override;

private:
    int shootTimerTicks;
};

#endif // !PLANT_HPP__