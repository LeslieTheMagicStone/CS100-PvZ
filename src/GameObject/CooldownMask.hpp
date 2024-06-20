#ifndef COOLDOWNMASK_HPP
#define COOLDOWNMASK_HPP

#include "GameObject.hpp"

class CooldownMask : public GameObject
{
public:
  CooldownMask(int x, int y, int lifeTimeTicks);
  void Update() override;
  void OnClick() override;

private:
  int m_lifeTimeTicks;
};

#endif // !COOLDOWNMASK_HPP