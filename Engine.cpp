#include "include/Engine.h"
#include "include/TimerSystem.h"

Engine::Engine() {}

Engine::~Engine() {}

Engine& Engine::getInstance() {
	static Engine instance;
	return  instance;
}

void Engine::start(sf::RenderWindow* win) {
	quit = false;
	last = std::clock();
	Engine::win = win;
	while (Engine::win->isOpen()) update();
}

void Engine::update() {
	now = std::clock();
	//testing for firing timed event
	sf::Event event;
	while (Engine::win->pollEvent(event)) {
		/*
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			std::cout << "woooooooooooo" << std::endl;
		}
		*/
		if (event.type == sf::Event::Closed) {
			std::cout << "Good bye";
			Engine::win->close();
		}
	}
	TimerSystem::getInstance().tick();
	if (TimerSystem::getInstance().flip) world->tick(now - last);
	last = now;
}

void Engine::add_system(ECS::EntitySystem* es) {
	world->registerSystem(es);
	world->enableSystem(es);
}