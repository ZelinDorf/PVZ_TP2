#include "Plant_PVZ.h"
#include "Zombie_PVZ.h"
#include "Projectile.h"

Plant_PVZ::Plant_PVZ()
{
	mCurrentState = PlantState::Idle;

	mShootTime = 0.25f;
	mShootProgress = 0.f;
}

void Plant_PVZ::AddZombie(Zombie_PVZ* zombie)
{
	mZombies.push_back(zombie);
}

void Plant_PVZ::OnUpdate()
{
	if (IsDead())
		Destroy();

	for (int i = 0; i < mZombies.size(); i++)
	{
		if (!mZombies[i]->IsDead())
			mZombies.erase(mZombies.begin() + i);
		TransitionTo(PlantState::Idle);
	}

	for (Zombie_PVZ* zombi : mZombies)
	{
		if (zombi->GetPosition().x <= 1000)
			TransitionTo(PlantState::Shoot);
		else
			TransitionTo(PlantState::Idle);
	}

	if(mCurrentState == PlantState::Shoot)
	{
		mShootProgress += GetDeltaTime();

		if (mShootProgress >= mShootTime)
		{
			mShootProgress = 0;
			 
			Projectile* bullet = CreateEntity<Projectile>(15, sf::Color::Blue);
			//bullet->SetRigidBody(true);
			bullet->SetTag(3);

			bullet->SetPosition(this->GetPosition().x + 75, this->GetPosition().y);
			bullet->GoToDirection(1280, this->GetPosition().y, 150.f);
		}
	}

}

void Plant_PVZ::OnCollision(Entity* collidedWith)
{
	if (collidedWith->IsTag(1))//zombie
		TakeDamage(1);
}

bool Plant_PVZ::TransitionTo(PlantState newState)
{
	int currentStateIndex = static_cast<int>(mCurrentState);
	int newStateIndex = static_cast<int>(newState);

	if (mTransitions[currentStateIndex][newStateIndex] == 0)
		return false;

	mCurrentState = newState;

	return true;
}
