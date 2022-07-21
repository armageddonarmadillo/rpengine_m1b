#pragma once
#include "component.h"
#include "ECS.h"

class InputSystem : public ECS::EntitySystem
{
public:
	InputSystem();
	~InputSystem();
	void tick(ECS::World* world, float deltatime) override;
};

