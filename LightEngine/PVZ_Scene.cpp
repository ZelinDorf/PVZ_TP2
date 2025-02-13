#include "PVZ_Scene.h"
#include "Plant_PVZ.h"
#include "Projectile.h"
#include "Zombie_PVZ.h"
#include "Debug.h"

#include <iostream>

void PVZ_Scene::OnInitialize()
{
	pPlant1 = CreateEntity<Plant_PVZ>(50, sf::Color::Green);
	pPlant1->SetPosition(100, 150);
	pPlant1->SetRigidBody(true);
	pPlant1->SetLife(500.f);
	pPlant1->SetTag((int)Tag::Plant);

	pPlant2 = CreateEntity<Plant_PVZ>(50, sf::Color::Green);
	pPlant2->SetPosition(100, 350);
	pPlant2->SetRigidBody(true);
	pPlant2->SetLife(500.f);
	pPlant2->SetTag((int)Tag::Plant);

	pPlant3 = CreateEntity<Plant_PVZ>(50, sf::Color::Green);
	pPlant3->SetPosition(100, 550);
	pPlant3->SetRigidBody(true);
	pPlant3->SetLife(500.f);
	pPlant3->SetTag((int)Tag::Plant);

	pRectUp = new Debug();
	pRectDown = new Debug();

}

void PVZ_Scene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (event.mouseButton.y >= 75 && event.mouseButton.y <= 225
			|| event.mouseButton.y >= 275 && event.mouseButton.y <= 425
			|| event.mouseButton.y >= 475 && event.mouseButton.y <= 625)
		{
			Projectile* bullet = CreateEntity<Projectile>(15, sf::Color::Blue);
			bullet->SetRigidBody(true);
			bullet->SetTag((int)Tag::Projectile);

			if (event.mouseButton.y >= 75 && event.mouseButton.y <= 225)
			{
				bullet->SetPosition(pPlant1->GetPosition().x + 75, pPlant1->GetPosition().y);
				bullet->GoToDirection(1280, 150, 150.f);
			}
			if (event.mouseButton.y >= 275 && event.mouseButton.y <= 425)
			{
				bullet->SetPosition(pPlant2->GetPosition().x + 75, pPlant2->GetPosition().y);
				bullet->GoToDirection(1280, 350, 150.f);
			}
			if (event.mouseButton.y >= 475 && event.mouseButton.y <= 625)
			{
				bullet->SetPosition(pPlant3->GetPosition().x + 75, pPlant3->GetPosition().y);
				bullet->GoToDirection(1280, 550, 150.f);
			}
		}

		std::cout << event.mouseButton.x << event.mouseButton.y << std::endl;
	}

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		if(event.mouseButton.y >= 75 && event.mouseButton.y <= 225
			|| event.mouseButton.y >= 275 && event.mouseButton.y <= 425 
			|| event.mouseButton.y >= 475 && event.mouseButton.y <= 625)
		{
			Zombie_PVZ* zombie = CreateEntity<Zombie_PVZ>(35, sf::Color::Red);
			zombie->SetRigidBody(true);
			zombie->SetLife(10);
			zombie->SetTag((int)Tag::Zombie);

			if (event.mouseButton.y >= 75 && event.mouseButton.y <= 225)
			{
				zombie->SetPlant(pPlant1);
				zombie->SetPosition(event.mouseButton.x, event.mouseButton.y);
				//zombie->GoToPosition(100, 150, 75.f);
				pPlant1->AddZombie(zombie);
			}
			if (event.mouseButton.y >= 275 && event.mouseButton.y <= 425)
			{
				zombie->SetPlant(pPlant2);
				zombie->SetPosition(event.mouseButton.x, event.mouseButton.y);
				zombie->GoToPosition(100, 350, 75.f);
				pPlant2->AddZombie(zombie);
			}
			if (event.mouseButton.y >= 475 && event.mouseButton.y <= 625)
			{
				zombie->SetPlant(pPlant3);
				zombie->SetPosition(event.mouseButton.x, event.mouseButton.y);
				zombie->GoToPosition(100, 550, 75.f);
				pPlant3->AddZombie(zombie);
			}
		}


	}
}

void PVZ_Scene::OnUpdate()
{
	pPlant1->GoToPosition(100, 150, 1000);
	pPlant2->GoToPosition(100, 350, 1000);
	pPlant3->GoToPosition(100, 550, 1000);

	pRectUp->DrawRectangle(45.f, 75.f, 1280, 150.f, sf::Color::Magenta);
	pRectDown->DrawRectangle(45.f, 475.f, 1280, 150.f, sf::Color::Magenta);
}
