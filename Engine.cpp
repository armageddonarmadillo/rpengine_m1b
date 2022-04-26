#include "Engine.h"

Engine::Engine() {}

Engine::~Engine() {}

Engine& Engine::getInstance() {
	static Engine instance;
	return  instance;
}

void Engine::start(sf::RenderWindow* win) {
	quit = false;
	Engine::win = win;
	while (Engine::win->isOpen()) update();
}

void Engine::update() {
	//testing for firing timed event
	sf::Event event;
	while (Engine::win->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			std::cout << "Good bye";
			Engine::win->close();
		}
	}
	world->tick(10.0f);
}

void Engine::add_system(ECS::EntitySystem* es) {
	world->registerSystem(es);
	world->enableSystem(es);
}