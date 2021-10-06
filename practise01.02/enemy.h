#pragma once
#include "BoxCollider.h"
#include <iostream>
#include "GameObject.h"
#include "Sprite.h"
#include "Star.h"
#include "Sound.h"
#include "Player.h"

class enemy :
    public GameObject
{

public:

	enum Direction
	{
		RIGHT,
		LEFT
	};

	enemy(Window& window);
	~enemy();

	int GetVelocity();
	Vector2D GetPosition();
	bool GetEnemyDead();
	void SetVelocity(int velocity);
	void Behavior();
	void Respawn(Star& coin);
	void SetDirection(int x, int y);
	const BoxCollider& GetCollider() const;
	void Update( Player& player, Star& coin);
	void Render(Window& window);

private:

	int m_velocity;
	bool isEnemyDead = false;
	int spawnTimer;
	BoxCollider m_collider;
	Direction m_facingDirection;
	Sprite m_image;
	Sound m_roar;
	Vector2D m_direction;
};

