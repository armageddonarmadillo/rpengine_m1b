#pragma once
#include "component.h"
#include "ECS.h"
struct Click {
	int x, y;

	Click(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class PlatformSystem : public ECS::EntitySystem
{
public:
	float ix, iy, fx, fy, w, h;
	std::list<Click*>* points;
	std::list<sf::RectangleShape>* rects;
	bool down;
	PlatformSystem();
	~PlatformSystem();
	void tick(ECS::World* world, float deltatime) override;
};
