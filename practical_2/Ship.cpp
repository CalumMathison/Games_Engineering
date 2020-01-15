#include "Ship.h"
#include "Game.h"

using namespace sf;
using namespace std;

//Ship Class
Ship::Ship() { }

Ship::Ship(IntRect ir) : Sprite()
{
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
}

void Ship::Update(const float &dt) { }

Ship::~Ship() = default;

//Invader Class
bool Invader::direction = false;
float Invader::speed = 24;

Invader::Invader() : Ship() { }

Invader::Invader(IntRect ir, Vector2f pos) : Ship(ir)
{
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float& dt)
{
	Ship::Update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16))
	{
		direction = !direction;
		for (int i = 0; i < ships.size(); ++i)
		{
			ships[i]->move(0, 24);
		}
	}
}

//Player class
float Player::speed = 200;

Player::Player() : Ship(IntRect(160, 32, 32, 32))
{
	setPosition({ gameWidth * 0.5f, gameHeight - 32.0f });
}

void Player::Update(const float& dt)
{
	Ship::Update(dt);
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.move(-speed * dt, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.move(speed * dt, 0);
	}

	if (player.getPosition().x < 0)
	{
		player.setPosition(0, player.getPosition().y);
	}
	else if (player.getPosition().x > gameWidth - 32)
	{
		player.setPosition(gameWidth - 32, player.getPosition().y);
	}
}