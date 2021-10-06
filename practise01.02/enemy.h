#pragma once
#include "BoxCollider.h"
#include <iostream>
#include "GameObject.h"
#include "Sprite.h"
#include "Coin.h"
#include "Sound.h"
#include "Player.h"

class Enemy : public GameObject
{
public:

	enum Direction
	{
		Right,
		Left
	};
	Enemy(Window& window);
	~Enemy();

	int GetVelocity();
	bool GetEnemyDead();
	Vector2D GetPosition();
	const BoxCollider& GetCollider() const;

	void SetVelocity(int velocity);
	void SetDirection(int x, int y);

	void Behavior();
	void Respawn(Coin& coin);
	void Update(Player& player, Coin& coin);
	void Render(Window& window);

private:

	int m_velocity;
	bool m_isEnemyDead;
	int m_spawnTimer;
	BoxCollider m_collider;
	Direction m_facingDirection;
	Sprite m_image;
	Sound m_roar;
	Vector2D m_direction;
};