#include "GameObject.hpp"
#include "GameWorld.hpp"

// Your everything begins from here.
GameObject::GameObject(const ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : ObjectBase(imageID, x, y, layer, width, height, animID), m_isDead(false) {}

void GameObject::Destroy() { m_isDead = true; }
bool GameObject::GetDead() const { return m_isDead; }

Generator::Generator(pGameWorld gameWorld, const ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
    : GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld) {}
void Generator::Instantiate(std::shared_ptr<GameObject> gameObject) { m_gameWorld->AddToGameObjects(gameObject); }

Background::Background()
    : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}
void Background::Update() {}
void Background::OnClick() {}

PlantingSpot::PlantingSpot(pGameWorld gameWorld, int x, int y)
    : Generator(gameWorld, IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION) {}
void PlantingSpot::Update() {}
void PlantingSpot::OnClick() { Instantiate(std::make_shared<SunFlower>(m_gameWorld, GetX(), GetY())); }

Plant::Plant(pGameWorld gameWorld, ImageID imageID, int x, int y, AnimID animID)
    : Generator(gameWorld, imageID, x, y, LAYER_PLANTS, 60, 80, animID) {}

SunFlower::SunFlower(pGameWorld gameWorld, int x, int y)
    : Plant(gameWorld, IMGID_SUNFLOWER, x, y, ANIMID_IDLE_ANIM), sunTimerTicks(randInt(30, 600)) {}
void SunFlower::Update()
{
    if (GetDead())
        return;
    if (sunTimerTicks == 0)
    {
        Instantiate(std::make_shared<GeneratedSun>(m_gameWorld, GetX(), GetY()));
        sunTimerTicks = 600;
    }
    else
        sunTimerTicks--;
}
void SunFlower::OnClick() {}

Sun::Sun(pGameWorld gameWorld, int x, int y, int lifeTimeTicks)
    : GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM), m_gameWorld(gameWorld), m_isGrounded(false), m_lifeTimeTicks(lifeTimeTicks), m_groundedTicks(0) {}
void Sun::Update()
{
    if (!m_isGrounded && m_lifeTimeTicks == 0)
        m_isGrounded = true;

    if (!m_isGrounded)
    {
        m_lifeTimeTicks--;
        return;
    }

    if (m_groundedTicks++ < 300)
        return;
    Destroy();
}
void Sun::OnClick()
{
    m_gameWorld->UpdateSun(25);
    Destroy();
}

NaturalSun::NaturalSun(pGameWorld gameWorld, int x, int y)
    : Sun(gameWorld, x, y, randInt(63, 263)) {}
void NaturalSun::Update()
{
    Sun::Update();
    if (m_isGrounded)
        return;
    MoveTo(GetX(), GetY() - 2);
}

GeneratedSun::GeneratedSun(pGameWorld gameWorld, int x, int y)
    : Sun(gameWorld, x, y, 12), m_ySpeed(4) {}
void GeneratedSun::Update()
{
    Sun::Update();
    if (m_isGrounded)
        return;
    MoveTo(GetX() - 1, GetY() + (m_ySpeed--));
}