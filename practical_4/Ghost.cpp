#include "Ghost.h"

using namespace sf;
using namespace std;

Ghost::Ghost(Color c) : _speed(200.0f), Entity(make_unique<CircleShape>(15.0f))
{
	_shape->setFillColor(c);
	_shape->setOrigin(Vector2f(15.0f, 15.0f));
}

void Ghost::Update(double dt)
{


	Entity::Update(dt);
}

void Ghost::Render(RenderWindow& window) const
{
	window.draw(*_shape);
}