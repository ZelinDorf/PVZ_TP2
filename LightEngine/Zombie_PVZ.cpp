#include "Zombie_PVZ.h"
#include "Plant_PVZ.h"
#include "Projectile.h"
#include <iostream>

void Zombie_PVZ::SetPlant(Plant_PVZ* plant)
{
	pPlant = plant;
	mCurrentState = ZombieState::Walk;
}

void Zombie_PVZ::OnUpdate()
{
	if (IsDead())
		Destroy();

	if (pPlant->IsDead())
		mCurrentState = ZombieState::Idle;

	if (mCurrentState == ZombieState::Walk)
		GoToPosition(pPlant->GetPosition().x, pPlant->GetPosition().y, 100.f);

	if (mCurrentState == ZombieState::Idle)
		mSpeed = 0.f;


	//if (mShape.getPosition().x <= pPlant->GetPosition().x + 55)
	//	mSpeed = 0.f;

	//std::cout << Life::GetHP() << std::endl;
}

void Zombie_PVZ::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(3))//projectile
		TakeDamage(1);
}

bool Zombie_PVZ::TransitionTo(ZombieState newState)
{
	int currentStateIndex = static_cast<int>(mCurrentState);
	int newStateIndex = static_cast<int>(newState);

	if (mTransitions[currentStateIndex][newStateIndex] == 0)
		return false;

	mCurrentState = newState;

	return true;
}
