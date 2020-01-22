#pragma once
#include "Entity.h"

using namespace sf;

class Player : public Entity
{
private:
	float _speed;
public:
	void Update(double dt) override;
	Player();
	void Render(RenderWindow& window) const override;
};