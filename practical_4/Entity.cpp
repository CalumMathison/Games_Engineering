#include "Entity.h"

using namespace std;
using namespace sf;

const Vector2f Entity::GetPosition() { return _position; }

void Entity::SetPosition(const Vector2f& pos) { _position = pos; }

void Entity::Move(const Vector2f& pos) { _position += pos; }

void Entity::Update(const double dt)
{
	_shape->setPosition(_position);
}

Entity::Entity(unique_ptr<Shape> s) : _shape(move(s)) { }