#include "Damager.hpp"

Damager::Damager(int damage, bool isEnemy)
    : m_damage(damage) {}

int Damager::GetDamage() const
{
    return m_damage;
}
