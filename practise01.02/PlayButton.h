#pragma once
#include "GameObject.h"
#include "BoxCollider.h"
#include "Sprite.h"
#include "Input.h"
class PlayButton :
    public GameObject
{
public:
	
	PlayButton(Window& window);
	~PlayButton();

	void SetState(int button);

	virtual void Update(Input& input, Window& window);
	virtual void Render(Window& window);

private:

	Vector2D m_direction;
	BoxCollider m_collider;
	Sprite m_image;
	int m_button;
	int m_gamestate;
	int m_velocity;
};

