#pragma once
#include "component.h"
#include "ECS.h"

class PhysicsSystem : public ECS::EntitySystem
{
public:
	PhysicsSystem();
	~PhysicsSystem();
	void tick(ECS::World* world, float deltatime) override;

	bool collides(
		ECS::ComponentHandle<BoxCollider> collider,
		ECS::ComponentHandle<BoxCollider> collidee,
		float x, float y
	);

	bool collides(
		ECS::ComponentHandle<BoxCollider> collider,
		sf::RectangleShape collidee,
		float x, float y
	);

	bool collides(
		ECS::ComponentHandle<BoxCollider> collider,
		ECS::ComponentHandle<BoxCollider> collidee
	);

	void side_collide(
		ECS::ComponentHandle<Transform> transform,
		ECS::ComponentHandle<BoxCollider> collider,
		ECS::ComponentHandle<BoxCollider> collidee
	);

	void side_collide(
		ECS::ComponentHandle<Transform> transform,
		ECS::ComponentHandle<BoxCollider> collider,
		sf::RectangleShape collidee
	);

	void side_collide(
		ECS::Entity* collider,
		ECS::Entity* collidee
	);

};

