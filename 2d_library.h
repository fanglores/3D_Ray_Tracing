#pragma once

struct Vec2
{
	// vector coordinates
	float x, y;

	//default constructor
	Vec2(float X, float Y);

	// vector operations
	Vec2 operator+(const Vec2& v);
	Vec2 operator-(const Vec2& v);
	Vec2 operator*(const Vec2& v);
	Vec2 operator/(const Vec2& v);

	// vector and number operations
	Vec2 operator+(const float& v);
	Vec2 operator-(const float& v);
	Vec2 operator*(const float& v);
	Vec2 operator/(const float& v);

};

// sub functions
float distance(const Vec2& v, const Vec2& u);