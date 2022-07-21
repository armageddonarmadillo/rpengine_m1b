#include "include/Renderer.h"
Renderer::Renderer() {
	//renderlist = new std::list<sf::Drawable>();
}
Renderer::~Renderer() {}

void Renderer::tick(ECS::World* world, float deltaTime) {
	Engine::getInstance().win->clear();		//CLEARS SCREEN
	//clear is in platformsys

	world->each<Transform, Sprite2D>([&](ECS::Entity* ent,
		ECS::ComponentHandle<Transform> transform,
		ECS::ComponentHandle<Sprite2D> sprite) -> void {
			if (texture_map.count(sprite->p) < 1) {
				texture_map[sprite->p] = load_texture(sprite->p);
			}

			if (sprite->s.getTexture() == nullptr) {
				sprite->s.setTexture(*texture_map[sprite->p]);
				sprite->w = sprite->s.getGlobalBounds().width;
				sprite->h = sprite->s.getGlobalBounds().height;
			}

			sprite->s.setPosition(transform->x, transform->y);

			//renderlist->push_back(sprite->s);

			/*for (int i = 0; i < renderlist->size(); i++) {
				Engine::getInstance().win->draw(renderlist[i]);
			}*/

			Engine::getInstance().win->draw(sprite->s);
		});

	//Engine::getInstance().win->display();	//DRAWS BUFFER TO SCREEN
	//display is in platformsys
}

sf::Texture* Renderer::load_texture(std::string p) {
	sf::Texture* t = new sf::Texture();

	if (!t->loadFromFile(p)) {
		std::cerr <<
			"Error: Failed to load image: " <<
			p <<
			".\nAre you pointing to the correct directory?" <<
			std::endl;

		system("pause");
		exit(EXIT_FAILURE);
	}

	return t;
}