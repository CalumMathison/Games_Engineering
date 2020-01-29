#pragma once
#include "ecm.h"

using namespace sf;

class Ghost : public Entity
{
private:
	//float _speed;
public:
	void Update(double dt) override;
	Ghost();
	void Render() override;
};