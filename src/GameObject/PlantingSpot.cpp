#include "PlantingSpot.hpp"
#include "GameWorld.hpp"

PlantingSpot::PlantingSpot(pGameWorld gameWorld, int x, int y)
    : Generator(gameWorld, IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {}

void PlantingSpot::Update() {}

void PlantingSpot::OnClick()
{
    switch (m_gameWorld->GetSelectedSeedType())
    {
    case SeedType::NONE:
        break;
    case SeedType::SUNFLOWER:
        Instantiate(std::make_shared<Sunflower>(m_gameWorld, GetX(), GetY()));
        break;
    }
    m_gameWorld->SetSelectedSeedType(SeedType::NONE);
}