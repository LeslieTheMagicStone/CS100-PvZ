#ifndef SUN_HPP__
#define SUN_HPP__

#include "GameObject.hpp"

class Sun : public GameObject
{
public:
  Sun(pGameWorld gameWorld, int x, int y, int lifeTimeTicks);
  void Update() override;
  void OnClick() override;

protected:
  bool m_isGrounded;

private:
  pGameWorld m_gameWorld;
  int m_lifeTimeTicks;
  int m_groundedTicks;
};

class NaturalSun : public Sun
{
public:
  NaturalSun(pGameWorld gameWorld, int x, int y);
  void Update() override;
};

class GeneratedSun : public Sun
{
public:
  GeneratedSun(pGameWorld gameWorld, int x, int y);
  void Update() override;

private:
  int m_ySpeed;
};

#endif // !SUN_HPP__