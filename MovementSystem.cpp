#include "include/MovementSystem.h"
#include <iostream>
#define out std::cout
#define line std::endl
#define xspeed 3.f
#define yspeed 10.f
#define STATE enum state {	\
	idle = 0,				\
	walk = 1,				\
	jump = 2,				\
	hit = 3,				\
	punch = 4,				\
	kick = 5,				\
	punch_air = 6,			\
	kick_air = 7,			\
	ko = 8					\
}

MovementSystem::MovementSystem() {}
MovementSystem::~MovementSystem() {}
void MovementSystem::tick(ECS::World* world, float deltatime) {
	world->each<Transform, Input, Animator>(
		[&](
			ECS::Entity* ent,
			ECS::ComponentHandle<Transform> transform,
			ECS::ComponentHandle<Input> input,
			ECS::ComponentHandle<Animator> anim
			) -> void {
				transform->xs = input->a ? -xspeed : input->d ? xspeed : 0;
				transform->ys = (transform->ys == 0 && input->w) ? -yspeed : transform->ys;
				transform->px = transform->x;
				transform->py = transform->y;
				transform->x += transform->xs;
				transform->y += transform->ys;
				/*
					2 things can happen:
					- when you press a face left (flip)
					- when you press d no flip

					No need to flip if we're facing the correct direction
					MUST flip is we're facing the wrong direction
					MUST remain in flipped orientation until another direction is given
				*/
				if (input->a) anim->flip = true;
				if (input->d) anim->flip = false;

				STATE;
				if (transform->xs == 0) anim->r = idle;
				if (transform->xs != 0) anim->r = walk;
				if (transform->ys < 0) anim->r = jump;
				//if (transform->xs >= 0) anim->r = 1; //LEFT VERSION (FLIP)
		});
}