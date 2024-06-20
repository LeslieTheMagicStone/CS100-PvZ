#include "PlantingSpot.hpp"
#include "GameWorld.hpp"

PlantingSpot::PlantingSpot(pGameWorld _pGameWorld, int x, int y)
    : GameObject(_pGameWorld, IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {}

void PlantingSpot::Update() {}

void PlantingSpot::OnClick()
{
    switch (m_pGameWorld->GetSelectedSeedType())
    {
    case SeedType::NONE:
        break;
    case SeedType::SUNFLOWER:
        Instantiate(std::make_shared<Sunflower>(m_pGameWorld, GetX(), GetY()));
        break;
    }
    m_pGameWorld->SetSelectedSeedType(SeedType::NONE);
}