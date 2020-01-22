#pragma once
#include "Entity.h"

using namespace sf;

class Ghost : public Entity
{
private:
	float _speed;
public:
	void Update(double dt) override;
	Ghost(Color c);
	void Render(RenderWindow& window) const override;
};