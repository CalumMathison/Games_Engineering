#pragma once 

#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace sf;

struct EntityManager
{
	vector<shared_ptr<Entity>> list;
	void Update(double dt);
	void Render();
};

class Entity
{
protected: 
	unique_ptr<Shape> _shape;
	Vector2f _position;
	Entity(unique_ptr<Shape> shp);
public:
	Entity() = delete;
	virtual ~Entity() = default;

	virtual void Update(const double dt);
	virtual void Render(RenderWindow& window) const = 0;

	const Vector2f GetPosition();
	void SetPosition(const Vector2f& pos);
	void Move(const Vector2f& pos);
};