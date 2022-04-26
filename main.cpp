#include "main.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Engine.h"
#include "Renderer.h"
#include "AnimationSystem.h"

int main(int argc, char* args[]) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Engine");
	Engine& instance = Engine::getInstance();
	instance.world = ECS::World::createWorld();
	instance.add_system(new Renderer());
	instance.add_system(new AnimationSystem());

	ECS::Entity* guy, * bg;
	bg = instance.world->create();
	bg->assign<Transform>(0, 0);
	bg->assign<Sprite2D>("./assets/bg.jpg");
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 32; y++) {
			guy = instance.world->create();
			guy->assign<Transform>(x * 25, y * 32);
			guy->assign<Sprite2D>("./assets/herosheet.png");
			guy->assign<Animator>(32, 32, 200.f);
		}
	}

	instance.start(&window);
	return 0;
}
