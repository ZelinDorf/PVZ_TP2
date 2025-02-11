#include "Zombie_PVZ.h"
#include "Plant_PVZ.h"

void Zombie_PVZ::SetPlant(Plant_PVZ* plant)
{
	pPlant = plant;
}

void Zombie_PVZ::OnUpdate()
{
	if (mShape.getPosition().x <= pPlant->GetPosition().x + 100)
		mSpeed = 0.f;
}
