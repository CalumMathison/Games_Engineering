#pragma once
#include "cmp_actor_movement.h"

class EnemyAiMovement : public ActorMovementComponent
{
public:
	EnemyAiMovement() = delete;
	explicit EnemyAiMovement(Entity* p);
	~EnemyAiMovement() = default;

	void Update(double dt) override;
	void Render() override { }
};