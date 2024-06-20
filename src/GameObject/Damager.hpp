#ifndef DAMAGER_HPP__
#define DAMAGER_HPP__

#include "GameObject.hpp"

class Damager: virtual public GameObject
{
public:
    Damager(int damage, bool isEnemy);

    int GetDamage() const;

    bool GetIsEnemy() const;

private:
    int m_damage;
    bool m_isEnemy;
};

#endif // !DAMAGER_HPP__