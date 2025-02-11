#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Plant_PVZ : public Entity
{

public:

	void OnCollision(Entity* collidedWith) override;
};

