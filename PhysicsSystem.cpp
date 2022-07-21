#include "include/PhysicsSystem.h"
#include <iostream>
#define gravity .50123f
#define ground 575.f

PhysicsSystem::PhysicsSystem() {}

PhysicsSystem::~PhysicsSystem() {}

void PhysicsSystem::tick(ECS::World* world, float deltatime) {
	world->each<BoxCollider>([&](
		ECS::Entity* ent,
		ECS::ComponentHandle<BoxCollider> box
		) -> void {
			//apply gravity here
			ent->get<Transform>()->ys += gravity;

			//ground check
			if (ent->get<Transform>()->y + ent->get<Animator>()->h >= ground) {
				ent->get<Transform>()->y = ground - ent->get<Animator>()->h;
				ent->get<Transform>()->ys = 0;
			}

			//landed check
			ent->get<Transform>()->landed = ent->get<Transform>()->ys == 0;

			/*
			THIS IS COLLISION AGAINST OTHER BOXCOLLIDERS
			world->each<BoxCollider>([&](
				ECS::Entity* e,
				ECS::ComponentHandle<BoxCollider> b
				) -> void {
					if (!(ent == e)) {
						box->update_collider(ent->get<Transform>()->x, ent->get<Transform>()->y, ent->get<Animator>()->w, ent->get<Animator>()->h);
						b->update_collider(e->get<Transform>()->x, e->get<Transform>()->y, e->get<Animator>()->w, e->get<Animator>()->h);

						if (collides(box, b)) {
							std::cout << "A COLLISION HAS OCCURRED" << std::endl;
							return;
						}
					}
				});*/
		});
}

bool PhysicsSystem::collides(
	ECS::ComponentHandle<BoxCollider> collider,
	ECS::ComponentHandle<BoxCollider> collidee,
	float x, float y
) {
	return (
		collider->R >= collidee->L &&
		collider->L <= collidee->R &&
		collider->B >= collidee->T &&
		collider->T <= collidee->B
		);
}

bool PhysicsSystem::collides(
	ECS::ComponentHandle<BoxCollider> collider,
	sf::RectangleShape collidee,
	float x, float y
) {
	return (
		collider->R >= collidee.getPosition().x &&
		collider->L <= collidee.getPosition().x + collidee.getGlobalBounds().width &&
		collider->B >= collidee.getPosition().y &&
		collider->T <= collidee.getPosition().y + collidee.getGlobalBounds().height
		);
}

bool PhysicsSystem::collides(
	ECS::ComponentHandle<BoxCollider> collider,
	ECS::ComponentHandle<BoxCollider> collidee
) {
	return (
		collider->R >= collidee->L &&
		collider->L <= collidee->R &&
		collider->B >= collidee->T &&
		collider->T <= collidee->B
		);
}

void PhysicsSystem::side_collide(
	ECS::ComponentHandle<Transform> transform,
	ECS::ComponentHandle<BoxCollider> collider,
	ECS::ComponentHandle<BoxCollider> collidee
) {

}

void PhysicsSystem::side_collide(
	ECS::ComponentHandle<Transform> transform,
	ECS::ComponentHandle<BoxCollider> collider,
	sf::RectangleShape collidee
) {

}

void PhysicsSystem::side_collide(
	ECS::Entity* collider,
	ECS::Entity* collidee
) {

}