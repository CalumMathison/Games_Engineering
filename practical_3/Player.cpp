#include "Player.h"
using namespace sf;
using namespace std;

void Player::Update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Entity::move(Vector2f(0, -_speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Entity::move(Vector2f(0, _speed * dt));
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Entity::move(Vector2f(_speed * dt, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Entity::move(Vector2f(-_speed * dt, 0));
	}

	Entity::Update(dt);
}

Player::Player() : _speed(200.0f), Entity(make_unique<CircleShape>(25.0f))
{
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.0f, 25.0f));
}

void Player::Render(RenderWindow& window) const
{
	window.draw(*_shape);
}