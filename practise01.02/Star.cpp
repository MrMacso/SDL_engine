#include "Star.h"

Star::Star(Window& window)
{
		m_image.Load("assets/images/Coin_silver.png", window);
		m_image.SetSpriteDimension(50, 50);
		m_image.SetImageDimension(6, 1, 3072, 512);
		m_image.IsAnimated(true);
		m_image.IsAnimationLooping(true);
		m_image.SetAnimationVelocity(2);
		m_position = (50, 50);
		m_sound.Load("assets/music/Coins.mp3");


}

Star::~Star()
{
	m_image.Unload();
}

void Star::Update(Player& player)
{
	if (m_collider.IsColliding(player.GetCollider()))
	{
		player.AddCoin(1);
		m_sound.Play(1);
		m_position = (2000, 2000);
	}
	m_collider.SetDimension(50, 50);
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
	m_image.Update();
}

void Star::Render(Window& window)
{
	m_image.Render(m_position.x, m_position.y, m_angle, window);
}
