#ifndef SUN_HPP__
#define SUN_HPP__

#include "GameObject.hpp"

class Sun : public GameObject
{
public:
  Sun(pGameWorld _pGameWorld, int x, int y, int lifeTimeTicks);
  void Update() override;
  void OnClick() override;

protected:
  bool m_isGrounded;

private:
  int m_lifeTimeTicks;
  int m_groundedTicks;
};

class NaturalSun : public Sun
{
public:
  NaturalSun(pGameWorld _pGameWorld, int x, int y);
  void Update() override;
};

class GeneratedSun : public Sun
{
public:
  GeneratedSun(pGameWorld _pGameWorld, int x, int y);
  void Update() override;

private:
  int m_ySpeed;
};

#endif // !SUN_HPP__