#include "Seed.hpp"
#include "CooldownMask.hpp"
#include "GameWorld.hpp"

Seed::Seed(pGameWorld _pGameWorld, ImageID imageID, int x, int y, SeedType seedType, int cost, int cooldownTicks)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION), m_seedType(seedType), m_cost(cost), m_cooldownTicks(cooldownTicks) {}

void Seed::OnClick()
{
    if (!m_pGameWorld->TryCostSun(m_cost))
        return;
    m_pGameWorld->SetSelectedSeedType(m_seedType);
    Instantiate(std::make_shared<CooldownMask>(m_pGameWorld, GetX(), GetY(), m_cooldownTicks));
}

void Seed::Update() {}

SunflowerSeed::SunflowerSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_SUNFLOWER, x, y, SeedType::SUNFLOWER, 50, 240) {}

PeashooterSeed::PeashooterSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_PEASHOOTER, x, y, SeedType::PEASHOOTER, 100, 240) {}

WallnutSeed::WallnutSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_WALLNUT, x, y, SeedType::WALLNUT, 50, 900) {}

CherryBombSeed::CherryBombSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_CHERRY_BOMB, x, y, SeedType::CHERRYBOMB, 150, 1200) {}

RepeaterSeed::RepeaterSeed(pGameWorld _pGameWorld, int x, int y)
    : Seed(_pGameWorld, IMGID_SEED_REPEATER, x, y, SeedType::REPEATER, 200, 240) {}
