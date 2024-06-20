#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "Plant.hpp"
#include "Seed.hpp"

class PlantingSpot : public GameObject
{
public:
  PlantingSpot(pGameWorld _pGameWorld, int x, int y);
  void Update() override;
  void OnClick() override;
};

#endif // !PLANTINGSPOT_HPP__