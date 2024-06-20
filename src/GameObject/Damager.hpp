#ifndef DAMAGER_HPP__
#define DAMAGER_HPP__

#include "GameObject.hpp"
#include "Damageable.hpp"

class Damager : virtual public GameObject
{
public:
    Damager(int damage, bool isEnemy);

    int GetDamage() const;

    bool GetIsEnemy() const;

    bool CheckColliding(std::shared_ptr<GameObject> other) const;

    virtual void OnCollision(std::shared_ptr<Damageable> other);

private:
    int m_damage;
    bool m_isEnemy;
    int m_isColliding;
};

#endif // !DAMAGER_HPP__