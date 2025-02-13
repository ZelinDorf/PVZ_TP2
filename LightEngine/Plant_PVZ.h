#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Life.h"

class Zombie_PVZ;

class Plant_PVZ : public Entity, public Life
{
	std::vector<Zombie_PVZ*> mZombies;

	float mShootTime;
	float mShootProgress;

public:

	enum class PlantState
	{
		Idle,
		Shoot,

		Count
	};
	static constexpr int StateCount = static_cast<int>(PlantState::Count);

private:
	PlantState mCurrentState;

	int mTransitions[StateCount][StateCount] =
	{
		//I ,S
		{ 0 ,1},//Idle
		{ 1 ,0}//Shoot
	};

public:
	Plant_PVZ();

	void AddZombie(Zombie_PVZ* zombie);
	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
	bool TransitionTo(PlantState newState);
};

