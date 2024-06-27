#ifndef SIMPLECOLLISIONBOX_HPP__
#define SIMPLECOLLISIONBOX_HPP__

#include "GameObject.hpp"

class SimpleCollisionBox : public GameObject
{
public:
    SimpleCollisionBox(pGameWorld _pGameWorld, int x, int y, int width, int height);
    void Update() override;
    void OnClick() override;
};

#endif // !SIMPLECOLLISIONBOX_HPP__