#include "include/InputSystem.h"
#include "include/Engine.h"
#include <iostream>

InputSystem::InputSystem() {}
InputSystem::~InputSystem() {}
void InputSystem::tick(ECS::World* world, float deltatime) {
	world->each<Input>([&](ECS::Entity* ent,
		ECS::ComponentHandle<Input> input) -> void {
			//KEYBOARDING
			input->w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
			input->a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
			input->s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
			input->d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

			//MOUSING
			input->lm = sf::Mouse::isButtonPressed(sf::Mouse::Left);
			input->rm = sf::Mouse::isButtonPressed(sf::Mouse::Right);

			//if (input->lm) std::cout << "X: " << sf::Mouse::getPosition().x << ", Y: " << sf::Mouse::getPosition().y << std::endl;
		});
}