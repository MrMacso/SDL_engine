#pragma once

#include "Vector2D.h"

class BoxCollider
{

public:

	void SetPosition(int x, int y);
	void SetDimension(int width, int height);
	Vector2D GetPosition();
	Vector2D GetDimension();
	void Update();
	bool IsColliding(const BoxCollider& secondBox) const;



private:
	Vector2D m_min;
	Vector2D m_max;
	Vector2D m_position;
	Vector2D m_dimension;

};

