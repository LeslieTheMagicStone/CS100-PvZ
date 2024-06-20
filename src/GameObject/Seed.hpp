#ifndef SEED_HPP__
#define SEED_HPP__

#include "GameObject.hpp"
#include "SeedType.hpp"

class Seed : public Generator
{
public:
  Seed(pGameWorld gameWorld, ImageID imageID, int x, int y, SeedType seedType, int cost, int cooldownTicks);
  void Update() override;
  void OnClick() override;

private:
  SeedType m_seedType;
  int m_cost;
  int m_cooldownTicks;
};

class SunflowerSeed : public Seed
{
public:
  SunflowerSeed(pGameWorld gameWorld, int x, int y);
};

#endif // !SEED_HPP__