#ifndef VECTORMOVEMENTCOMPONENT_H
#define VECTORMOVEMENTCOMPONENT_H
#include <math.h>
#include "GameObject.h"

class VectorMovementComponent : 
	public MovementComponent
{
private:
	float vx = 0;
	float vy = 0;
	float direction = 0;
public:
	VectorMovementComponent();
	VectorMovementComponent(float speed, float direction);
	void update(GameObject & gameObject, float timeStep)  override;
	~VectorMovementComponent();

	inline float getSpeed() { return sqrt(vx * vx + vy * vy); }
	inline void setSpeed(float speed) { vx = cos(direction) * speed; vy = sin(direction) * speed; }
	inline float getDirection() { return atan2(vy, vx); }
	inline void setDirection(float d) { float speed = getSpeed(); vx = cos(d) * speed; vy = sin(d) * speed; }
	inline void accelerate(float ax, float ay) { vx += ax; vy += ay; }
};
#endif