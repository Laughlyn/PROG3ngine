#pragma once
#include <algorithm>
#include <math.h>

template<typename T>
inline extern T norm(const T & value, const T & min, const T & max)
{
	if (max - min == (T)0)
	{
		throw std::invalid_argument("Divide by zero!");
	}
	else
	{
		return (value - min) / (max - min);
	}
};

template<typename T>
inline extern T lerp(T norm, T min, T max)
{
	return (max - min) * norm + min;
};

template<typename T>
inline extern T map(T value, T sourceMin, T sourceMax, T destMin, T destMax)
{
	return lerp(norm(value, sourceMin, sourceMax), destMin, destMax);
};

template<typename T>
inline extern T clamp(const T & value, const T & min, const T & max)
{
	return std::min(std::max(value, min), max);
};

template<typename T>
inline extern T distanceXY(const T & x0, const T & y0, const T & x1, const T & y1)
{
	T dx = x1 - x0;
	T dy = y1 - y0;
	return sqrt(dx * dx + dy * dy);
}

template<typename T>
inline extern bool inRange(const T & value, const T & min, const T & max)
{
	return (value >= std::min(min, max)) && (value <= std::max(min, max));
}

template<typename T>
inline extern bool rangeIntersect(const T & min0, const T & max0, const T & min1, const T & max1)
{
	return ((std::max(min0, max0) >= std::min(min1, max1)) &&
		(std::min(min0, max0) <= std::max(min1, max1)));
}

template<typename T, typename V>
inline extern bool pointRectCollision(const T & x, const T & y, const V & rect )
{
	return (inRange(x, rect.x, rect.x + rect.w) &&
		inRange(y, rect.y, rect.y + rect.h));
}

template<typename T>
inline extern bool rectRectCollision(const T & r0, const T & r1)
{
	return rangeIntersect(r0.x, r0.x + r0.w, r1.x, r1.x + r1.w) &&
		rangeIntersect(r0.y, +r0.y + r0.h, r1.y, r1.y + r1.h);
}

//Random? srand()?
template<typename T>
inline extern int randomInt(T min, T max)
{
	return std::floor(min + random() * (max - min + 1));
}

template<typename T>
inline extern T degreesToRads(T deg)
{
	return deg / 180 * PI;
}

template<typename T>
inline extern T radsToDegrees(T rad)
{
	return rad * 180 / PI;
}

//typedef struct {
//	Sint16 x, y;
//	Uint16 r;
//} Circle;