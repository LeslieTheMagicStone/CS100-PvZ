#include "Damageable.hpp"

Damageable::Damageable(int maxHealth, bool isEnemy)
    : m_maxHealth(maxHealth), m_health(maxHealth), m_isEnemy(isEnemy) {}

void Damageable::TakeDamage(int damage)
{
    if (m_health > damage)
        m_health -= damage;
    else
        m_health = 0;
}

int Damageable::GetHealth() const
{
    return m_health;
}

int Damageable::GetMaxHealth() const
{
    return m_maxHealth;
}

bool Damageable::GetIsEnemy() const
{
    return m_isEnemy;
}
