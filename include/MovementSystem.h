#pragma once
#include "component.h"
#include "ECS.h"

class MovementSystem : public ECS::EntitySystem
{
public:
	MovementSystem();
	~MovementSystem();
	void tick(ECS::World* world, float deltatime) override;
};



