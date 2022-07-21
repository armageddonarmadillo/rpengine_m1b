#include "include/AISystem.h"
#define xspeed 1.f

AISystem::AISystem() {}

AISystem::~AISystem() {}

void AISystem::tick(ECS::World* world, float deltaTime) {
	world->each<AI, Transform>(
		[&](ECS::Entity* e, ECS::ComponentHandle<AI> ai, ECS::ComponentHandle<Transform> transform) {
			if (transform->x >= ai->origin + ai->distance_from_origin ||
				transform->x <= ai->origin - ai->distance_from_origin)
				ai->direction_flag = !ai->direction_flag;
			transform->xs = ai->direction_flag ? xspeed : -xspeed;
			transform->x += transform->xs;
		}
	);
}