#pragma once
#include "component.h"
#include "ECS.h"
#include <atlstr.h>

class LoaderSystem : public ECS::EntitySystem
{
public:
	LoaderSystem();
	~LoaderSystem();

	static LoaderSystem& getInstance();
	void tick(ECS::World* world, float deltatime) override;
	std::list<sf::RectangleShape>* load_level(CString path);
};
