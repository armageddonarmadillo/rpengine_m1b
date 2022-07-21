#pragma once
#include "Engine.h"
#include "ECS.h"

class Renderer : public ECS::EntitySystem
{
public:
	//std::list<sf::Drawable>* renderlist;

	Renderer();
	~Renderer();

	void tick(ECS::World* world, float deltaTime) override;

private:
	std::unordered_map<std::string, sf::Texture*> texture_map;
	sf::Texture* load_texture(std::string p);
};

