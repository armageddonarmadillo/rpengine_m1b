#pragma once
#include "component.h"
#include "ECS.h"

class AnimationSystem : public ECS::EntitySystem
{
public:
	AnimationSystem();
	~AnimationSystem();
	void tick(ECS::World* world, float deltatime) override;
};

