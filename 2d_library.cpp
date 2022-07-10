#include "2d_library.h"
#include <math.h>


Vec2::Vec2(float X, float Y) : x(X), y(Y) {}

Vec2 Vec2::operator+(const Vec2& v) { return Vec2(this->x + v.x, this->y + v.y); }
Vec2 Vec2::operator-(const Vec2& v) { return Vec2(this->x - v.x, this->y - v.y); }
Vec2 Vec2::operator*(const Vec2& v) { return Vec2(this->x * v.x, this->y * v.y); }
Vec2 Vec2::operator/(const Vec2& v) { return Vec2(this->x / v.x, this->y / v.y); }

Vec2 Vec2::operator+(const float& v) { return Vec2(this->x + v, this->y + v); }
Vec2 Vec2::operator-(const float& v) { return Vec2(this->x - v, this->y - v); }
Vec2 Vec2::operator*(const float& v) { return Vec2(this->x * v, this->y * v); }
Vec2 Vec2::operator/(const float& v) { return Vec2(this->x / v, this->y / v); }


float distance(const Vec2& v, const Vec2& u)
{
	return sqrt((v.x - u.x) * (v.x - u.x) + (v.y - u.y) * (v.y - u.y));
}