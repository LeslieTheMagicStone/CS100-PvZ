#include "Seed.hpp"
#include "CooldownMask.hpp"
#include "GameWorld.hpp"

Seed::Seed(pGameWorld _pGameWorld, ImageID imageID, int x, int y, ActionType actionType, int cost, int cooldownTicks)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION), m_actionType(actionType), m_cost(cost), m_cooldownTicks(cooldownTicks) {}

void Seed::OnClick()
{
    if (m_pGameWorld->GetSelectedActionType() != ActionType::NONE)
        return;
    if (!m_pGameWorld->TryCostSun(m_cost))
        return;
    m_pGameWorld->SetSelectedActionType(m_actionType);
    Instantiate(std::make_shared<CooldownMask>(m_pGameWorld, GetX(), GetY(), m_cooldownTicks));
}

void Seed::Update() {}

SunflowerSeed::SunflowerSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_SUNFLOWER, x, y, ActionType::SUNFLOWER, 50, 240) {}

PeashooterSeed::PeashooterSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_PEASHOOTER, x, y, ActionType::PEASHOOTER, 100, 240) {}

WallnutSeed::WallnutSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_WALLNUT, x, y, ActionType::WALLNUT, 50, 900) {}

CherryBombSeed::CherryBombSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_CHERRY_BOMB, x, y, ActionType::CHERRYBOMB, 150, 1200) {}

RepeaterSeed::RepeaterSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_REPEATER, x, y, ActionType::REPEATER, 200, 240) {}
