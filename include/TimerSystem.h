#pragma once
#include "component.h"
#include "ECS.h"

class TimerSystem : public ECS::EntitySystem
{
public:
	std::clock_t start;
	float index, check, dt, ticker, fps, frame_time;
	bool flip;

	TimerSystem();
	~TimerSystem();

	static TimerSystem& getInstance();
	void tick();
	void tick(ECS::World* world, float deltatime) override;
};
