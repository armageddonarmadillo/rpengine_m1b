#pragma once
#include "Engine.h"
#include "ECS.h"

class AISystem : public ECS::EntitySystem
{
public:

	AISystem();
	~AISystem();

	void tick(ECS::World* world, float deltaTime) override;
};

