#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ship : public Sprite 
{
protected:
	IntRect _sprite;
	//Default constructo is hidden
	Ship();
public:
	//Constructor that takes a sprite
	explicit Ship(IntRect ir);
	//Pure virtual deconstructor
	virtual ~Ship() = 0;
	//Update, virtual so can be overridden
	virtual void Update(const float& dt);

};