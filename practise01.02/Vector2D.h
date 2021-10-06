#pragma once
#include "math.h"
class Vector2D
{

public:
	Vector2D(int x = 0, int y = 0);

	int GetX();
	int GetY();

	void SetX(int x);
	void SetY(int y);

	Vector2D Add(const Vector2D& second);
	Vector2D Subtract(const Vector2D& second);
	Vector2D Scale(int scaler);
	int Distance(const Vector2D& vector);
	double Magnitude();
	Vector2D Negation();



public:

	int x;
	int y;


};

