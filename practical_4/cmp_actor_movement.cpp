#include "cmp_actor_movement.h"
#include <LevelSystem.h>

using namespace sf;

void ActorMovementComponent::Update(double dt) { }

ActorMovementComponent::ActorMovementComponent(Entity *p) 
	: _speed(100.0f), Component(p) { }

bool ActorMovementComponent::ValidMove(const Vector2f& pos)
{
	return (LevelSystem::GetTileAt(pos) != LevelSystem::WALL);
}

void ActorMovementComponent::Move(const Vector2f& p)
{
	auto pp = _parent->GetPosition() + p;
	//if (ValidMove(pp))
	//{
		_parent->SetPosition(pp);
	//}
}

void ActorMovementComponent::Move(float x, float y)
{
	Move(Vector2f(x, y));
}

float ActorMovementComponent::GetSpeed() const
{
	return _speed;
}

void ActorMovementComponent::SetSpeed(float speed)
{
	_speed = speed;
}
