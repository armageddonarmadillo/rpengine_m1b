#include "include/TimerSystem.h"
#include <iostream>

TimerSystem::TimerSystem() {
	TimerSystem::start = std::clock();
	TimerSystem::fps = 60.f;
	TimerSystem::frame_time = 1.f / 60.f;
	TimerSystem::check = frame_time; //this will be divided by desired fps
	TimerSystem::dt = 0.f;
	TimerSystem::ticker = 0.f;
	TimerSystem::flip = false;
}
TimerSystem::~TimerSystem() {}

TimerSystem& TimerSystem::getInstance() {
	static TimerSystem instance;
	return  instance;
}

void TimerSystem::tick() {
	flip = false;
	index = ((std::clock() - start) / (double)CLOCKS_PER_SEC);
	if (index >= check) {
		check += frame_time;
		flip = true;
	}
}

void TimerSystem::tick(ECS::World* world, float deltatime) {
	world->each<Time>([&](ECS::Entity* ent,
		ECS::ComponentHandle<Time> time) -> void {
			dt += deltatime;
			tick();
		});
}