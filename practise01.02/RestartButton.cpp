#include "RestartButton.h"

RestartButton::RestartButton(Window& window)
{
	m_image.Load("assets/images/restart.png", window);
	m_image.SetImageDimension(1, 1, 400, 400);
	m_image.SetSpriteDimension(400, 400);

	m_position.x = 200;
	m_position.y = 200;
	m_velocity = 0;
}

RestartButton::~RestartButton()
{
	m_image.Unload();
}

void RestartButton::SetVelocity(int velocity)
{
	m_velocity = velocity;
}

void RestartButton::Update(Input& input)
{
}

void RestartButton::Render(Window& window)
{
	m_image.Render(m_position.x, m_position.y, m_angle, window);
}
