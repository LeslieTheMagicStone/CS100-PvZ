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
    case SeedType::PEASHOOTER:
        Instantiate(std::make_shared<Peashooter>(m_pGameWorld, GetX(), GetY()));
        break;
    case SeedType::WALLNUT:
        Instantiate(std::make_shared<Wallnut>(m_pGameWorld, GetX(), GetY()));
        break;
    case SeedType::CHERRYBOMB:
        Instantiate(std::make_shared<CherryBomb>(m_pGameWorld, GetX(), GetY()));
        break;
    case SeedType::REPEATER:
        Instantiate(std::make_shared<Repeater>(m_pGameWorld, GetX(), GetY()));
        break;
    }
    m_pGameWorld->SetSelectedSeedType(SeedType::NONE);
}