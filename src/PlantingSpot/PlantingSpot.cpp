#include "PlantingSpot.hpp"
#include "GameWorld.hpp"

PlantingSpot::PlantingSpot(pGameWorld _pGameWorld, int x, int y)
    : GameObject(_pGameWorld, IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {}

void PlantingSpot::Update() {}

void PlantingSpot::OnClick()
{
    switch (m_pGameWorld->GetSelectedActionType())
    {
    case ActionType::NONE:
        break;
    case ActionType::SUNFLOWER:
        Plant(std::make_shared<Sunflower>(m_pGameWorld, GetX(), GetY()));
        break;
    case ActionType::PEASHOOTER:
        Plant(std::make_shared<Peashooter>(m_pGameWorld, GetX(), GetY()));
        break;
    case ActionType::WALLNUT:
        Plant(std::make_shared<Wallnut>(m_pGameWorld, GetX(), GetY()));
        break;
    case ActionType::CHERRYBOMB:
        Plant(std::make_shared<CherryBomb>(m_pGameWorld, GetX(), GetY()));
        break;
    case ActionType::REPEATER:
        Plant(std::make_shared<Repeater>(m_pGameWorld, GetX(), GetY()));
        break;
    }
}

void PlantingSpot::Plant(pGameObject plant)
{
    Instantiate(plant);
    m_pGameWorld->SetSelectedActionType(ActionType::NONE);
}
