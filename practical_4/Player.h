#pragma once
#include "ecm.h"

using namespace sf;

class Player : public Entity
{
private:
	//float _speed;
public:
	void Update(double dt) override;
	Player();
	void Render() override;
};