#pragma once
#include "Entity.h"

class Plant_PVZ;

class Zombie_PVZ : public Entity
{
	Plant_PVZ* pPlant;

public:

	void SetPlant(Plant_PVZ* plant);
	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
};

