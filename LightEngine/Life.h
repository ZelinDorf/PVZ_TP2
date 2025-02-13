#pragma once

class Life
{
	float mCurrentHealth;
	float mMaxHealth;

public:
	Life();

	void SetLife(float maxHealth);
	float GetHP();

	bool IsDead();
	void TakeDamage(float dmg);
};

