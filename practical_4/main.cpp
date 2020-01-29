#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "ecm.h"
#include "Player.h"
#include "Ghost.h"
#include "SystemRenderer.h"
#include "Pacman.h"

using namespace sf;
using namespace std;

uint16_t _gameHeight = 600, _gameWidth = 800;
EntityManager em;

void Load()
{

	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->Load();
	menuScene->Load();

	activeScene = menuScene;
}

void Update(RenderWindow& window)
{
	//Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();

	//Check and consume events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	//Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}

	activeScene->Update(dt);
}

void Render(RenderWindow& window)
{
	//Draw Everything
	activeScene->Render();
	Renderer::Render();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(_gameWidth, _gameHeight), "Maze Game");
	Renderer::Initialise(window);
	Load();
	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}

	return 0;
}