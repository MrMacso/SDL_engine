#pragma once
#include "BoxCollider.h"
#include <iostream>
#include "GameObject.h"
#include "Sprite.h"
#include "Star.h"
#include "Sound.h"
#include "Player.h"

class enemy : public GameObject
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
	bool GetEnemyDead();
	Vector2D GetPosition();
	const BoxCollider& GetCollider() const;

	void SetVelocity(int velocity);
	void SetDirection(int x, int y);

	void Behavior();
	void Respawn(Star& coin);
	void Update(Player& player, Star& coin);
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