#pragma once
#include "Vector.h"
 
class Particle
{
public:
	Particle();

	void accelerate(Vector);
	void update();
	float angleTo(Particle);
	float distanceTo(Particle);
	void gravitateTo(Particle);

	~Particle();
private:
	Vector position;
	Vector velocity;
	float mass = 1;
	float radius = 1;
	float bounce = -1;
	float friction = 1;
	Vector gravity;
};