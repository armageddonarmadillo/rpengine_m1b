#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../include/Engine.h"
#include "../include/Renderer.h"
#include "../include/AnimationSystem.h"
#include "../include/InputSystem.h"
#include "../include/MovementSystem.h"
#include "../include/PhysicsSystem.h"
#include "../include/TimerSystem.h"
#include "../include/PlatformSystem.h"
#include "../include/AISystem.h"

//convert engine to doodle jump

int main(int argc, char* args[]) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Engine");
	Engine& instance = Engine::getInstance();
	instance.world = ECS::World::createWorld();
	instance.add_system(new AnimationSystem());
	instance.add_system(new InputSystem());
	instance.add_system(new Renderer());
	instance.add_system(new PlatformSystem());
	instance.add_system(new MovementSystem());
	instance.add_system(new PhysicsSystem());
	instance.add_system(new TimerSystem());
	instance.add_system(new AISystem());

	ECS::Entity* guy, * bg, * tux;
	bg = instance.world->create();
	bg->assign<Transform>(0, 0);
	bg->assign<Sprite2D>("../assets/bg.jpg");
	tux = instance.world->create();
	tux->assign<BoxCollider>();
	tux->assign<Transform>(300, 300);
	tux->assign<Sprite2D>("../assets/tux.png");
	tux->assign<Animator>(56, 72, 200.f, 3, 9);
	tux->assign<Input>();
	tux->assign<Time>();
	guy = instance.world->create();
	guy->assign<Sprite2D>("../assets/herosheet.png");
	guy->assign<Animator>(32, 32, 32.f, 4, 1);
	guy->assign<Transform>(500, 500);
	guy->assign<BoxCollider>();
	guy->assign<Time>();
	guy->assign<AI>(guy->get<Transform>()->x);

	instance.start(&window);
	return 0;
}
