#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Player.h"
#include "levelsystem.h"

using namespace sf;
using namespace std;

Player player;

void Load()
{
	ls::LoadLevelFile("res/maze_2.txt");

	for (size_t y = 0; y < ls::GetHeight(); ++y)
	{
		for (size_t x = 0; x < ls::GetWidth(); x++)
		{
			cout << ls::GetTile({ x,y });
		}
		cout << endl;
	}
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

	player.Update(dt);
}

void Render(RenderWindow& window)
{
	//Draw Everything
	ls::Render(window);
	player.Render(window);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Maze Game");
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