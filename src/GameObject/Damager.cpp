#include "Damager.hpp"

Damager::Damager(int damage, bool isEnemy)
    : m_damage(damage), m_isEnemy(isEnemy), m_isColliding(false) {}

int Damager::GetDamage() const
{
    return m_damage;
}

bool Damager::GetIsEnemy() const
{
    return m_isEnemy;
}

bool Damager::CheckColliding(std::shared_ptr<GameObject> other) const
{
    auto collidingX = (GetX() + GetWidth() / 2 < other->GetX() - other->GetWidth() / 2) ||
                      (GetX() - GetWidth() / 2 > other->GetX() + other->GetWidth() / 2);
    auto collidingY = (GetY() + GetHeight() / 2 < other->GetY() - other->GetHeight() / 2) ||
                      (GetY() - GetHeight() / 2 > other->GetY() + other->GetHeight() / 2);

    return collidingX && collidingY;
}

void Damager::OnCollision(std::shared_ptr<Damageable> other)
{
    if (other->GetIsEnemy() != m_isEnemy)
        other->TakeDamage(m_damage);
}
