#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "ECS.h"
#include "component.h"
#include <fstream>

class Engine
{
private:
	bool quit;
	std::clock_t last, now;
	Engine();
	~Engine();
	void update();

	// required to prevent a reference from being copied/moved/reassigned
	Engine(Engine& copy);				// hide copy constructor
	Engine(Engine&& o);					// hide move constructor
	Engine& operator= (Engine& copy);   // hide assignment operator

public:
	static Engine& getInstance();
	void start(sf::RenderWindow* win);
	void add_system(ECS::EntitySystem* es);

	sf::RenderWindow* win;
	ECS::World* world;
};

