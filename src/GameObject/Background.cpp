#include "Background.hpp"

Background::Background(pGameWorld _pGameWorld)
    : GameObject(_pGameWorld, IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}
    
void Background::Update() {}

void Background::OnClick() {}