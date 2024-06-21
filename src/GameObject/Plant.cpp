#include "Plant.hpp"
#include "Sun.hpp"
#include "GameWorld.hpp"
#include "Projectile.hpp"
#include "SimpleCollisionBox.hpp"

Plant::Plant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, CollisionCheckTag collisionCheckTag)
    : GameObject(_pGameWorld, imageID, x, y, LAYER_PLANTS, 60, 80, animID, collisionCheckTag) {}

void Plant::OnClick()
{
    if (m_pGameWorld->GetSelectedActionType() == ActionType::SHOVEL)
    {
        Destroy();
        m_pGameWorld->SetSelectedActionType(ActionType::NONE);
    }
}

EatablePlant::EatablePlant(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int maxHealth)
    : Plant(_pGameWorld, imageID, x, y, animID, CollisionCheckTag::EATABLEPLANT), m_maxHealth(maxHealth), m_health(maxHealth) {}

int EatablePlant::GetMaxHealth() const { return m_maxHealth; }

int EatablePlant::GetHealth() const { return m_health; }

void EatablePlant::TakeDamage(int damage)
{
    if (GetDead())
        return;

    m_health = std::max(0, m_health - damage);
    if (m_health == 0)
        Destroy();
}

Sunflower::Sunflower(pGameWorld _pGameWorld, int x, int y)
    : EatablePlant(_pGameWorld, IMGID_SUNFLOWER, x, y, ANIMID_IDLE_ANIM, 300), m_sunTimerTicks(randInt(30, 600)) {}

void Sunflower::Update()
{
    if (GetDead())
        return;

    if (m_sunTimerTicks == 0)
    {
        Instantiate(std::make_shared<GeneratedSun>(m_pGameWorld, GetX(), GetY()));
        m_sunTimerTicks = 600;
    }
    else
        m_sunTimerTicks--;
}

Shooter::Shooter(pGameWorld _pGameWorld, ImageID imageID, int x, int y, AnimID animID, int maxHealth, int shootIntervalTicks)
    : EatablePlant(_pGameWorld, imageID, x, y, animID, maxHealth),
      m_pShootRangeIndicator(std::make_shared<SimpleCollisionBox>(_pGameWorld, (WINDOW_WIDTH + x) / 2, y, WINDOW_WIDTH - x, LAWN_GRID_HEIGHT))
{
    Instantiate(m_pShootRangeIndicator);
}

void Shooter::OnDestroy()
{
    m_pShootRangeIndicator->Destroy();
}

bool Shooter::GetHasTarget()
{
    return m_pGameWorld->CheckZombieCollision(m_pShootRangeIndicator);
}

Peashooter::Peashooter(pGameWorld _pGameWorld, int x, int y)
    : Shooter(_pGameWorld, IMGID_PEASHOOTER, x, y, ANIMID_IDLE_ANIM, 300, 30), m_shootTimerTicks(0) {}

void Peashooter::Update()
{
    if (GetDead())
        return;

    if (m_shootTimerTicks == 0 && GetHasTarget())
    {
        Instantiate(std::make_shared<Pea>(m_pGameWorld, GetX() + 30, GetY() + 20));
        m_shootTimerTicks = 30;
    }
    if (m_shootTimerTicks > 0)
        m_shootTimerTicks--;
}

Wallnut::Wallnut(pGameWorld _pGameWorld, int x, int y)
    : EatablePlant(_pGameWorld, IMGID_WALLNUT, x, y, ANIMID_IDLE_ANIM, 4000), m_isCracked(false) {}

void Wallnut::Update()
{
    if (GetDead())
        return;
        
    if (!m_isCracked && GetHealth() * 3 < GetMaxHealth())
    {
        ChangeImage(IMGID_WALLNUT_CRACKED);
        m_isCracked = true;
    }
}

CherryBomb::CherryBomb(pGameWorld _pGameWorld, int x, int y)
    : Plant(_pGameWorld, IMGID_CHERRY_BOMB, x, y, ANIMID_IDLE_ANIM), m_timerTicks(15) {}

void CherryBomb::Update()
{
    if (m_timerTicks == 0)
    {
        Instantiate(std::make_shared<Explosion>(m_pGameWorld, GetX(), GetY()));
        Destroy();
    }
    else
        m_timerTicks--;
}

Repeater::Repeater(pGameWorld _pGameWorld, int x, int y)
    : Shooter(_pGameWorld, IMGID_REPEATER, x, y, ANIMID_IDLE_ANIM, 300, 30), m_shootTimerTicks(0), m_remainingShots(2), m_continuousShootTimerTicks(0) {}

void Repeater::Update()
{
    if (GetDead())
        return;

    if (m_shootTimerTicks == 0 && GetHasTarget())
    {
        m_remainingShots = 2;
        m_shootTimerTicks = 30;
    }

    if (m_continuousShootTimerTicks == 0 && m_remainingShots > 0)
    {
        m_remainingShots--;
        ShootPea();
        m_continuousShootTimerTicks = 5;
    }

    if (m_shootTimerTicks > 0)
        m_shootTimerTicks--;
    if (m_continuousShootTimerTicks > 0)
        m_continuousShootTimerTicks--;
}

void Repeater::ShootPea()
{
    Instantiate(std::make_shared<Pea>(m_pGameWorld, GetX() + 30, GetY() + 20));
}
