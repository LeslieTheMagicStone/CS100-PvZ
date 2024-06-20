#include "Sun.hpp"
#include "GameWorld.hpp"

Sun::Sun(pGameWorld _pGameWorld, int x, int y, int lifeTimeTicks)
    : GameObject(_pGameWorld, IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM), m_isGrounded(false), m_lifeTimeTicks(lifeTimeTicks), m_groundedTicks(0) {}
void Sun::Update()
{
    if (!m_isGrounded && m_lifeTimeTicks == 0)
        m_isGrounded = true;

    if (!m_isGrounded)
    {
        m_lifeTimeTicks--;
        return;
    }

    if (m_groundedTicks++ < 300)
        return;
    Destroy();
}
void Sun::OnClick()
{
    m_pGameWorld->UpdateSun(25);
    Destroy();
}

NaturalSun::NaturalSun(pGameWorld _pGameWorld, int x, int y)
    : Sun(_pGameWorld, x, y, randInt(63, 263)) {}
void NaturalSun::Update()
{
    Sun::Update();
    if (m_isGrounded)
        return;
    MoveTo(GetX(), GetY() - 2);
}

GeneratedSun::GeneratedSun(pGameWorld _pGameWorld, int x, int y)
    : Sun(_pGameWorld, x, y, 12), m_ySpeed(4) {}
void GeneratedSun::Update()
{
    Sun::Update();
    if (m_isGrounded)
        return;
    MoveTo(GetX() - 1, GetY() + (m_ySpeed--));
}