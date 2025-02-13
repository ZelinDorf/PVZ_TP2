#pragma once
#include "Entity.h"
#include "Life.h"

class Plant_PVZ;

class Zombie_PVZ : public Entity, public Life
{
	Plant_PVZ* pPlant;

public:

	enum class ZombieState
	{
		Idle,
		Walk,

		Count
	};
	static constexpr int StateCount = static_cast<int>(ZombieState::Count);

private:
	ZombieState mCurrentState;

	int mTransitions[StateCount][StateCount] =
	{
		//I ,W
		{ 0 ,1},//Idle
		{ 1 ,0}//Walk
	};

public:

	void SetPlant(Plant_PVZ* plant);
	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
	bool TransitionTo(ZombieState newState);
};

