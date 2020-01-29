#include "Ghost.h"

using namespace sf;
using namespace std;

void Ghost::Update(double dt)
{
	for (auto s : _components)
	{
		s->Update(dt);
	}

	//Entity::Update(dt);
}

void Ghost::Render()
{
	for (auto s : _components)
	{
		s->Render();
	}

	//Entity::Render();
}