#pragma once
#include <SFML/Graphics.hpp>
#include "ecm.h"

using namespace std;
using namespace sf;

class ShapeComponent : public Component
{
protected:
	shared_ptr<Shape> _shape;
public:
	ShapeComponent() = delete;
	explicit ShapeComponent(Entity* p);

	void Update(double dt) override;
	void Render() override;

	Shape& GetShape() const;

	template <typename T, typename Targs, typename params>
	void SetShape(Targs, params)
	{
		_shape.reset(new T(params));
	}
};