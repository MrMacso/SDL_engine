#include "PlayButton.h"

PlayButton::PlayButton(Window& window)
{
	m_position.x = 620; 
	m_position.y = 600;
	m_image.Load("assets/images/StartButton.png", window);
	m_image.SetSpriteDimension(300, 120);
	m_image.SetImageDimension(1, 1, 300, 120);
	m_image.IsAnimated(false);
	m_image.IsAnimationLooping(false);
	
}

PlayButton::~PlayButton()
{
	m_image.Unload();
}

void PlayButton::SetState(int button)
{
	m_button = button;
}

void PlayButton::Update(Input& input, Window& window)
{
	if (m_button == 1)
	{
		m_image.Load("assets/images/HowToPlayButton.png", window);
	}
	else if (m_button == 2)
	{
		m_image.Load("assets/images/BackButton.png", window);
	}
	else if (m_button == 3)
	{
		m_image.Load("assets/images/RestartButton.png", window);
	}
	else
	{
		m_image.Load("assets/images/StartButton.png", window);
	}

	m_image.Update();
}

void PlayButton::Render(Window& window)
{
	m_image.Render(m_position.x, m_position.y, m_angle, window, Sprite::NO_FLIP);
}
