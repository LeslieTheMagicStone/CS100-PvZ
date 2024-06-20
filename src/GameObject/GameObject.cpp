#include "GameObject.hpp"

// Your everything begins from here.
GameObject::GameObject(const ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID) {}

Background::Background()
    : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}
void Background::Update() {}
void Background::OnClick() {}

PlantingSpot::PlantingSpot(int x, int y)
    : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {}
void PlantingSpot::Update() {}
void PlantingSpot::OnClick() {}
