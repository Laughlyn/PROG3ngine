#include "Vector.h"
#include <math.h>


Vector::Vector()
{
}

Vector::Vector(float newX, float newY) : x(newX), y(newY)
{

}

void Vector::setX(float newX)
{
	x = newX;
}

void Vector::setY(float newY)
{
	y = newY;
}

float Vector::getX()
{
	return x;
}

float Vector::getY()
{
	return y;
}

void Vector::setAngle(float newAngle)
{
	float length = getLength();
	x = cos(newAngle) * length;
	y = sin(newAngle) * length;
}

float Vector::getAngle()
{
	return atan2(y, x);
}

void Vector::setLength(float length)
{
	float angle = getAngle();
	x = cos(angle) * length;
	y = sin(angle) * length;
}

float Vector::getLength()
{
	return sqrt(x * x + y * y);
}

Vector::~Vector()
{
}
