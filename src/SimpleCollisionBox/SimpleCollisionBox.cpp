#include "SimpleCollisionBox.hpp"
#include "GameWorld.hpp"

SimpleCollisionBox::SimpleCollisionBox(pGameWorld _pGameWorld, int x, int y, int width, int height)
    : GameObject(_pGameWorld, IMGID_NONE, x, y, LAYER_BACKGROUND, width, height, ANIMID_NO_ANIMATION) {}

void SimpleCollisionBox::Update() {}
void SimpleCollisionBox::OnClick() {}