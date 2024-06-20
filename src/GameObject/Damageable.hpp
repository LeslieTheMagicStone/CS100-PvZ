#ifndef DAMAGEABLE_HPP__
#define DAMAGEABLE_HPP__

#include "GameObject.hpp"

class Damageable
{
public:
    Damageable(int maxHealth, bool isEnemy);

    void TakeDamage(int damage);

    int GetHealth() const;
    int GetMaxHealth() const;

    bool GetIsEnemy() const;

private:
    int m_health;
    int m_maxHealth;
    bool m_isEnemy;
};

#endif // !DAMAGEABLE_HPP__