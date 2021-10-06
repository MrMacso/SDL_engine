#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Sound.h"
#include "BoxCollider.h"
#include "SDLText.h"
#include <string>
class Coin :
    public GameObject
{
public:
	Coin(Window& window);
	~Coin();

	void Update(Player& player);
	void Render(Window& window);

private:

	Vector2D m_direction;
	Vector2D m_distance;
	BoxCollider m_collider;
	Sprite m_image;
	Sound m_sound;

	std::string m_counterString;

	int state;
	int m_number;
};

