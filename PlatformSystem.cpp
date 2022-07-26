#include "include/PlatformSystem.h"
#include "include/Engine.h"
#include "include/LoaderSystem.h"
#include <iostream>
#include <iostream>
#define add push_back


PlatformSystem::PlatformSystem() {
	points = new std::list<Click*>();
	rects = LoaderSystem::getInstance().load_level("test.testfile");

}
PlatformSystem::~PlatformSystem() {}

void PlatformSystem::tick(ECS::World* world, float deltatime) {
	//Engine::getInstance().win->clear();		//CLEARS SCREEN
	//display is in renderer

	world->each<Input, Transform, Sprite2D>([&](ECS::Entity* ent,
		ECS::ComponentHandle<Input> input,
		ECS::ComponentHandle<Transform> transform,
		ECS::ComponentHandle<Sprite2D> sprite) -> void {
			if (input->lm) points->add(new Click(sf::Mouse::getPosition().x - Engine::getInstance().win->getPosition().x, sf::Mouse::getPosition().y - Engine::getInstance().win->getPosition().y));
			else {
				if (points->size() > 0) {
					sf::RectangleShape r;
					r.setSize(sf::Vector2f(points->back()->x - points->front()->x, points->back()->y - points->front()->y));
					r.setPosition(points->front()->x, points->front()->y);
					rects->add(r);
					points->clear();
				}
			}
			if (points->size() > 0) {
				//store initial points
				ix = points->front()->x;
				iy = points->front()->y;
				//store end points
				fx = points->back()->x;
				fy = points->back()->y;
				//store rectangle size
				w = fx - ix;
				h = fy - iy;
				//clear the points for next time
				//points->clear();
			}

			if (input->lm) {
				sf::RectangleShape rect;
				rect.setSize(sf::Vector2f(w, h));
				rect.setPosition(ix, iy);
				Engine::getInstance().win->draw(rect);
			}

			//platform removal
			for (std::list<sf::RectangleShape>::iterator r = rects->begin(); r != rects->end(); r++) {
				if (input->rm &&
					r->getPosition().x < sf::Mouse::getPosition().x - Engine::getInstance().win->getPosition().x &&
					sf::Mouse::getPosition().x - Engine::getInstance().win->getPosition().x < r->getPosition().x + r->getLocalBounds().width &&
					r->getPosition().y < sf::Mouse::getPosition().y - Engine::getInstance().win->getPosition().y &&
					sf::Mouse::getPosition().y - Engine::getInstance().win->getPosition().y < r->getPosition().y + r->getLocalBounds().height
					) {
					rects->erase(r);
					break;
				}
			}

			for (std::list<sf::RectangleShape>::iterator r = rects->begin(); r != rects->end(); r++) { //this iterates through the rects list. r IS a rect
				sf::RectangleShape fakerect;
				fakerect.setSize(sf::Vector2f(r->getLocalBounds().width, r->getLocalBounds().height));
				fakerect.setPosition(r->getPosition().x, r->getPosition().y);
				Engine::getInstance().win->draw(fakerect);
			}


			//this iterates through the rects list. r IS a rect
			for (std::list<sf::RectangleShape>::iterator r = rects->begin(); r != rects->end(); r++) {
				//do your collision in here
				if (transform->x < r->getPosition().x + r->getLocalBounds().width &&
					transform->x + sprite->w > r->getPosition().x &&
					transform->y < r->getPosition().y + r->getLocalBounds().height &&
					transform->y + sprite->h > r->getPosition().y) {
					if (transform->py + sprite->h < r->getPosition().y) {
						transform->y = transform->py;
						transform->ys = 0;
					}
					else if (transform->px > r->getPosition().x + r->getLocalBounds().width) transform->x = transform->px;
					else if (transform->px + sprite->w < r->getPosition().x) transform->x = transform->px;
					else if (transform->py > r->getPosition().y + r->getLocalBounds().height) transform->y = transform->py;
				}
			}
		});
	Engine::getInstance().win->display();
}