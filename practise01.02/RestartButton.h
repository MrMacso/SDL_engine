#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
class RestartButton :
    public GameObject

{
public:
	RestartButton(Window & window);
	~RestartButton();

	void SetVelocity(int velocity);

	virtual void Update(Input & input);
	virtual void Render(Window & window);

private:

	Vector2D m_direction;

	Sprite m_image;

	int m_velocity;
};


