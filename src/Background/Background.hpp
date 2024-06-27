#ifndef BACKGROUND_HPP__
#define BACKGROUND_HPP__

#include "GameObject.hpp"

class Background : public GameObject
{
public:
    Background(pGameWorld _pGameWorld);
    void Update() override;
    void OnClick() override;
};

#endif // !BACKGROUND_HPP__