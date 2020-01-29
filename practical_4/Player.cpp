#include "Player.h"

using namespace sf;
using namespace std;

void Player::Update(double dt)
{
	for (auto s : _components)
	{
		s->Update(dt);
	}

	//Entity::Update(dt);
}

void Player::Render()
{
	for (auto s : _components)
	{
		s->Render();
	}

	//Entity::Render();
}