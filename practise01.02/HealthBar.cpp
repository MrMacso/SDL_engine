#include "HealthBar.h"

HealthBar::HealthBar(Window& window)
{
	m_position.x = 20;
	m_position.y = 10;
	m_fill.Load("assets/images/Fill.png", window);
	m_fill.SetSpriteDimension(420, 80);
	m_fill.SetImageDimension(1, 1, 420, 80);

	m_border.Load("assets/images/Border.png", window);
	m_border.SetSpriteDimension(420, 80);
	m_border.SetImageDimension(1, 1, 420, 80);
}

HealthBar::~HealthBar()
{
}

void HealthBar::Update(Player& player)
{
	//FILL SCALES WITH THE PLAYERS HEALTH POINT
	m_fill.SetSpriteDimension(player.GetHealth() * 0.42f, 80);
}

void HealthBar::Render(Window& window)
{
	m_border.Render(m_position.x, m_position.y, m_angle, window, Sprite::NO_FLIP);
	m_fill.Render(m_position.x, m_position.y, m_angle, window, Sprite::NO_FLIP);
}
