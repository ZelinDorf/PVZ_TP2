
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "PVZ_Scene.h"

#include <cstdlib>
#include <crtdbg.h>

int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Plant VS Zombie", 60, sf::Color::Black);
	
	pInstance->LaunchScene<PVZ_Scene>();

	return 0;
}