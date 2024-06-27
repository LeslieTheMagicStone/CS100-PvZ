#ifndef SEED_HPP__
#define SEED_HPP__

#include "GameObject.hpp"

class Seed : public GameObject
{
public:
  Seed(pGameWorld _pGameWorld, ImageID imageID, int x, int y, ActionType actionType, int cost, int cooldownTicks);
  void Update() override;
  void OnClick() override;

private:
  ActionType m_actionType;
  int m_cost;
  int m_cooldownTicks;
};

class SunflowerSeed : public Seed
{
public:
  SunflowerSeed(pGameWorld _pGameWorld, int x, int y);
};

class PeashooterSeed : public Seed
{
public:
  PeashooterSeed(pGameWorld _pGameWorld, int x, int y);
};

class WallnutSeed : public Seed
{
public:
  WallnutSeed(pGameWorld _pGameWorld, int x, int y);
};

class CherryBombSeed : public Seed
{
  public:
    CherryBombSeed(pGameWorld _pGameWorld, int x, int y);
};

class RepeaterSeed : public Seed
{
  public:
    RepeaterSeed(pGameWorld _pGameWorld, int x, int y);
};

#endif // !SEED_HPP__