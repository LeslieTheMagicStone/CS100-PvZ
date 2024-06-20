#include "Seed.hpp"
#include "CooldownMask.hpp"
#include "GameWorld.hpp"

Seed::Seed(pGameWorld gameWorld, ImageID imageID, int x, int y, SeedType seedType, int cost, int cooldownTicks)
    : Generator(gameWorld, imageID, x, y, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION), m_seedType(seedType), m_cost(cost), m_cooldownTicks(cooldownTicks) {}

void Seed::OnClick()
{
    if (!m_gameWorld->TryCostSun(m_cost))
        return;
    m_gameWorld->SetSelectedSeedType(m_seedType);
    Instantiate(std::make_shared<CooldownMask>(GetX(), GetY(), m_cooldownTicks));
}

void Seed::Update() {}

SunflowerSeed::SunflowerSeed(pGameWorld gameWorld, int x, int y)
    : Seed(gameWorld, IMGID_SEED_SUNFLOWER, x, y, SeedType::SUNFLOWER, 50, 240) {}