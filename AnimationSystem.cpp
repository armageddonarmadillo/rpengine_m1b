#include "include/AnimationSystem.h"

AnimationSystem::AnimationSystem() {}
AnimationSystem::~AnimationSystem() {}
void AnimationSystem::tick(ECS::World* world, float deltatime) {
	world->each<Animator, Sprite2D>([&](ECS::Entity* ent,
		ECS::ComponentHandle<Animator> animator,
		ECS::ComponentHandle<Sprite2D> sprite) -> void {
			sprite->s.setTextureRect(
				sf::IntRect(animator->c * animator->w, animator->r * animator->h, animator->w, animator->h)
			);
			sprite->s.setScale(animator->flip ? -1.f : 1.f, 1.0f);

			animator->t += deltatime;
			if (animator->t > animator->ft) {
				animator->t = 0;
				animator->c = (animator->c + 1) % animator->cc;
			}
		});
}