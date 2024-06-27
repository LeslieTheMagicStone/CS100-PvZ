#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "GameObject.hpp"

class Shovel : public GameObject
{
public:
    Shovel(pGameWorld _pGameWorld, int x, int y);
    void Update() override;
    void OnClick() override;
};

#endif // !SHOVEL_HPP__