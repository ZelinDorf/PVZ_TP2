#pragma once
#include "Scene.h"

class Plant_PVZ;
class Debug;

class PVZ_Scene : public Scene
{
	Plant_PVZ* pPlant1;
	Plant_PVZ* pPlant2;
	Plant_PVZ* pPlant3;

	Debug* pRectUp;
	Debug* pRectDown;

public:

	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};

