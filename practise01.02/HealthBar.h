#pragma once
#include "Sprite.h"
#include "Player.h"
#include "Vector2D.h"
class HealthBar
{
public:
	enum State
	{
		BAR,
		BORDER,
		TOTAL
	};

	HealthBar(Window& window);
	~HealthBar();

	void Update(Player& player);
	void Render(Window& winodw);


private:
	float m_angle = 0.0f;
	Vector2D m_position;
	Sprite m_fill;
	Sprite m_border;
	
};

