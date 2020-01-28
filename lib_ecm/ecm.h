#pragma once
#include "maths.h"
#include <algorithm>
#include <memory>
#include <typeindex>
#include <vector>

using namespace std;
using namespace sf;

class Component;

class Entity 
{
protected:
	vector<shared_ptr<Component>> _components;
	Vector2f _position;
	float _rotation;
	bool _alive;		//Should be updated
	bool _visible;		//Should be rendered
	bool _forDeletion;	//Should be deleted
public:
	Entity();
	virtual ~Entity();
	virtual void Update(double dt);
	virtual void Render();

	const Vector2f& GetPosition() const;
	void SetPosition(const Vector2f& _position);
	bool Is_For_Deletion() const;
	float GetRotation() const;
	void SetRotation(float _rotation);
	bool IsAlive() const;
	void SetAlive(bool _alive);
	void SetForDelete();
	bool IsVisible() const;
	void SetVisible(bool _visible);
	templat
};

class Component 
{
protected:
	Entity* const _parent;
	bool _forDeletion;		//Should be removed
	explicit Component(Entity* const p);
public:
	Component() = delete;
	bool Is_For_Deletion() const;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual ~Component();
};