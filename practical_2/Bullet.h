#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite
{
public:
	//Updates all bullets
	static void Update(const float& dt) 
	{
		for (int i = 0; i < 256; i++)
		{
			bullets[i]._Update(dt);
		}
	};
	//Renders all bullets
	static void Render(sf::RenderWindow& window)
	{
		for (int i = 0; i < 256; i++)
		{
			window.draw(bullets[i]);
		}
	};
	//Choose an inactive bullet and use it
	static void Fire(const sf::Vector2f& pos, const bool mode)
	{
		bullets[++bulletPointer].setPosition(pos);
		bullets[bulletPointer]._mode = mode;
	};

	//Bullet(const sf::Vector2f& pos, const bool mode);
	~Bullet() = default;
protected:
	static unsigned char bulletPointer;
	static Bullet bullets[256];
	//Called by static update
	void _Update(const float& dt);
	Bullet();
	//false = player bullet, true = enemy bullet
	bool _mode;
};