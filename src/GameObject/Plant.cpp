#include "Plant.hpp"
#include "Sun.hpp"
#include "GameWorld.hpp"

Plant::Plant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_PLANTS, 60, 80, animID) {}

void Plant::OnClick()
{
    if (m_pGameWorld->GetSelectedActionType() == ActionType::SHOVEL)
    {
        Destroy();
        m_pGameWorld->SetSelectedActionType(ActionType::NONE);
    }
}

EatablePlant::EatablePlant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int maxHealth)
    : Plant(_pGameWorld, imageID, x, y, animID), m_maxHealth(maxHealth), m_health(maxHealth) {}

Sunflower::Sunflower(pGameWorld _pGameWorld, int x, int y)
    : EatablePlant(_pGameWorld, IMGID_SUNFLOWER, x, y, ANIMID_IDLE_ANIM, 300), m_sunTimerTicks(randInt(30, 600)) {}

void Sunflower::Update()
{
    if (GetDead())
        return;

    if (m_sunTimerTicks == 0)
    {
        Instantiate(std::make_shared<GeneratedSun>(m_pGameWorld, GetX(), GetY()));
        m_sunTimerTicks = 600;
    }
    else
        m_sunTimerTicks--;
}

Peashooter::Peashooter(pGameWorld _pGameWorld, int x, int y)
    : EatablePlant(_pGameWorld, IMGID_PEASHOOTER, x, y, ANIMID_IDLE_ANIM, 300), m_shootTimerTicks(0) {}

void Peashooter::Update()
{
    if (GetDead())
        return;

    // Instantiate(std::make_shared<Pea>(m_pGameWorld, GetX() + 30, GetY(), false));
}

Wallnut::Wallnut(pGameWorld _pGameWorld, int x, int y)
    : EatablePlant(_pGameWorld, IMGID_WALLNUT, x, y, ANIMID_IDLE_ANIM, 4000) {}

void Wallnut::Update() {}

CherryBomb::CherryBomb(pGameWorld _pGameWorld, int x, int y)
    : Plant(_pGameWorld, IMGID_CHERRY_BOMB, x, y, ANIMID_IDLE_ANIM), m_timerTicks(15) {}

void CherryBomb::Update() {}

Repeater::Repeater(pGameWorld _pGameWorld, int x, int y)
    : EatablePlant(_pGameWorld, IMGID_REPEATER, x, y, ANIMID_IDLE_ANIM, 300) {}

void Repeater::Update() {}