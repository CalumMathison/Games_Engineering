#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

const int gameWidth = 800;
const int gameHeight = 600;

void Load()
{

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