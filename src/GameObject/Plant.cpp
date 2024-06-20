#include "Plant.hpp"
#include "Sun.hpp"

Plant::Plant(pGameWorld gameWorld, ImageID imageID, int x, int y, AnimID animID)
    : Generator(gameWorld, imageID, x, y, LAYER_PLANTS, 60, 80, animID) {}

Sunflower::Sunflower(pGameWorld gameWorld, int x, int y)
    : Plant(gameWorld, IMGID_SUNFLOWER, x, y, ANIMID_IDLE_ANIM), sunTimerTicks(randInt(30, 600)) {}

void Sunflower::Update()
{
    if (GetDead())
        return;
    if (sunTimerTicks == 0)
    {
        Instantiate(std::make_shared<GeneratedSun>(m_gameWorld, GetX(), GetY()));
        sunTimerTicks = 600;
    }
    else
        sunTimerTicks--;
}

void Sunflower::OnClick() {}