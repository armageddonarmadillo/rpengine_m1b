#pragma once
#include "ECS.h"
#include "SFML/Graphics.hpp"

struct Transform {
public:
	ECS_DECLARE_TYPE;

	float x, px, y, py, xs, ys, rotation;
	bool landed;

	Transform(float nx, float ny) : x(nx), y(ny) {
		this->rotation = 0.f;
		this->xs = 0.f;
		this->ys = 0.f;
		this->py = 0.f;
		this->px = 0.f;
		this->landed = false;
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

	int w, h, c, cc, r, rr;
	//w = sprite width, h = sprite height, c = current column, r = current row, 
	//cc = total columns, rr = total rows
	float t, ft;		//t = (current) time, ft = frame time
	bool flip;

	Animator(int w, int h, float ft, int cc, int rr) {
		this->w = w;
		this->h = h;
		this->ft = ft;
		this->cc = cc;
		this->rr = rr;
		this->c = 0;
		this->r = 0;
		this->t = 0;
		this->flip = false;
	}
};
ECS_DEFINE_TYPE(Animator);

struct Input {
public:
	ECS_DECLARE_TYPE;

	bool w, a, s, d;
	bool lm, rm;
};
ECS_DEFINE_TYPE(Input);

struct BoxCollider {
public:
	ECS_DECLARE_TYPE;

	float L, R, T, B; //left side, right side, top side, bottom side (of box)

	BoxCollider() {
		this->L = 0;
		this->R = 0;
		this->T = 0;
		this->B = 0;
	}

	void update_collider(float x, float y, float w, float h) {
		this->L = x;
		this->R = x + w;
		this->T = y;
		this->B = y + h;
	}
};
ECS_DEFINE_TYPE(BoxCollider);

struct Time {
public:
	ECS_DECLARE_TYPE;

	float c, d;

	Time() {
		this->c = 0.f;
		this->d = 0.f;
	}
};
ECS_DEFINE_TYPE(Time);

struct AI {
	ECS_DECLARE_TYPE;

	float distance_from_origin, origin;
	bool direction_flag;

	AI(float origin) {
		this->origin = origin;
		this->distance_from_origin = 200.f;
		this->direction_flag = true;
	}
};
ECS_DEFINE_TYPE(AI);