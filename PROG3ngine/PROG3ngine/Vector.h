#pragma once

class Vector
{
public:
	Vector();
	Vector(float, float);

	void setX(float);
	void setY(float);
	float getX();
	float getY();
	void setAngle(float);
	float getAngle();
	void setLength(float);
	float getLength();
	
	Vector add(Vector);
	Vector subtract(Vector);
	Vector multiply(float);
	Vector divide(float);
	void addTo(Vector);
	void subtractFrom(Vector);
	void multiplyBy(float);
	void divideBy(float);

	~Vector();
private:
	float x = 0;
	float y = 0;
};

