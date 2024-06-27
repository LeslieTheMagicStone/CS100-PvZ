#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "Plant.hpp"

class PlantingSpot : public GameObject
{
public:
  PlantingSpot(pGameWorld _pGameWorld, int x, int y);
  void Update() override;
  void OnClick() override;

private:
  void Plant(pGameObject _pGameObject);
};

#endif // !PLANTINGSPOT_HPP__