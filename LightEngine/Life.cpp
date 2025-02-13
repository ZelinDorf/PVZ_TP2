#include "Life.h"

Life::Life()
{
}

void Life::SetLife(float maxHealth)
{
	mCurrentHealth = maxHealth;
	mMaxHealth = maxHealth;
}

float Life::GetHP()
{
	return mCurrentHealth;
}

bool Life::IsDead()
{
	if (mCurrentHealth <= 0)
		return true;

	return false;
}

void Life::TakeDamage(float dmg)
{
	mCurrentHealth -= dmg;
}
