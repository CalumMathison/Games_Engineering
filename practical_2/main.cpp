#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 600;

Texture spritesheet;
Sprite invader;

void Load()
{
	if (!spritesheet.loadFromFile("res/sprites/invaders_sheet.png"))
	{
		 cerr << "Failed to load spritesheet!" << endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(IntRect(0, 0, 32, 32));
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
}

void Render(RenderWindow& window)
{
	//Draw Everything
	window.draw(invader);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while(window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}

	return 0;
}