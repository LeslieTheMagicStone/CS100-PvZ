#include "GameObject.hpp"

class Plant : public GameObject
{
public:
    Plant() = delete;
    Plant(pGameWorld gameWorld, ImageID imageID, int x, int y, AnimID animID);
};

class Sunflower : public Plant
{
public:
    Sunflower(pGameWorld gameWorld, int x, int y);
    void Update() override;
    void OnClick() override;

private:
    int sunTimerTicks;
};