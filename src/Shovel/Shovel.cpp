#include "Shovel.hpp"
#include "GameWorld.hpp"

Shovel::Shovel(pGameWorld _pGameWorld, int x, int y)
    : GameObject(_pGameWorld, IMGID_SHOVEL, x, y, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION) {}

void Shovel::Update() {}

void Shovel::OnClick()
{
    auto selectedAction = m_pGameWorld->GetSelectedActionType();
    if (selectedAction == ActionType::SHOVEL)
        m_pGameWorld->SetSelectedActionType(ActionType::NONE);
    else if (selectedAction == ActionType::NONE)
        m_pGameWorld->SetSelectedActionType(ActionType::SHOVEL);
}