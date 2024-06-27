#include "CooldownMask.hpp"

CooldownMask::CooldownMask(pGameWorld _pGameWorld, int x, int y, int lifeTimeTicks)
    : GameObject(_pGameWorld, IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION), m_lifeTimeTicks(lifeTimeTicks) {}

void CooldownMask::Update()
{
    if (m_lifeTimeTicks == 0)
        Destroy();
    else
        m_lifeTimeTicks--;
}

void CooldownMask::OnClick() {}