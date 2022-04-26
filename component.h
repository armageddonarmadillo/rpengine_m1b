#pragma once
#include "ECS.h"
#include "SFML/Graphics.hpp"

struct Transform {
public:
	ECS_DECLARE_TYPE;

	float x, y, rotation;

	Transform(float nx, float ny) : x(nx), y(ny) {
		this->rotation = 0.0f;
	}
};
ECS_DEFINE_TYPE(Transform);

struct Sprite2D {
public:
	ECS_DECLARE_TYPE;

	sf::Sprite s;
	std::string p;
	int w, h;

	Sprite2D(std::string path) {
		this->p = path;
	}
};
ECS_DEFINE_TYPE(Sprite2D);

struct Animator {
public:
	ECS_DECLARE_TYPE;

	int w, h, c, r;		//w = sprite width, h = sprite height, c = current column, r = current row
	float t, ft;		//t = (current) time, ft = frame time

	Animator(int w, int h, float ft) {
		this->w = w;
		this->h = h;
		this->ft = ft;
		this->c = 0;
		this->r = 0;
		this->t = 0;
	}
};
ECS_DEFINE_TYPE(Animator);