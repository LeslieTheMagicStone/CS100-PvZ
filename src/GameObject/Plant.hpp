#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "GameObject.hpp"

class Plant : public GameObject
{
public:
    Plant() = delete;
    Plant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID);
};

class Sunflower : public Plant
{
public:
    Sunflower(pGameWorld _pGameWorld, int x, int y);
    void Update() override;
    void OnClick() override;

private:
    int sunTimerTicks;
};

class Peashooter : public Plant
{
public:
    Peashooter(pGameWorld _pGameWorld, int x, int y);
    void Update() override;
    void OnClick() override;

private:
    int shootTimerTicks;
};

#endif // !PLANT_HPP__