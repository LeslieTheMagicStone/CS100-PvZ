#include "Plant.hpp"
#include "Sun.hpp"

Plant::Plant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_PLANTS, 60, 80, animID) {}

Sunflower::Sunflower(pGameWorld _pGameWorld, int x, int y)
    : Plant(_pGameWorld, IMGID_SUNFLOWER, x, y, ANIMID_IDLE_ANIM), sunTimerTicks(randInt(30, 600)) {}

void Sunflower::Update()
{
    if (GetDead())
        return;
    if (sunTimerTicks == 0)
    {
        Instantiate(std::make_shared<GeneratedSun>(m_pGameWorld, GetX(), GetY()));
        sunTimerTicks = 600;
    }
    else
        sunTimerTicks--;
}

void Sunflower::OnClick() {}