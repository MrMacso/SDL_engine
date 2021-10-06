#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"
#include <iostream>
#include "Sound.h"

class Player : public GameObject
{

public:

	enum State
	{
		IDLE,
		RUN,
		ATTACK,
		HURT,
		DIE,
		TOTAL_STATES
	};
	enum Direction
	{ 
		RIGHT, 
		LEFT
	};
	
	Player(Window& window);
	~Player();
	
	int GetVelocity();
	int GetHealth();
	int GetCoin();

	bool GetIsAttacking();
	void SetHealth(int health);
	void AddCoin(int coin);
	void SetState(State state);
	void SetVelocity(int velocity);
	void SetIsAttacking(bool attack);
	void CheckHealth();
	void ReduceHealth(int damage);
	void IncreaseHealth(int heal);
	void AttackCollider();

	const BoxCollider& GetCollider() const;

	void Update(Input& input);
	void Render(Window& window);

private:
	
	int m_velocity;
	int m_health = 1000;
	int m_coin;

	bool m_isAttacking = false;
	BoxCollider m_collider;
	BoxCollider m_hitCollider;
	Direction m_facingDirection;
	Sprite m_image[TOTAL_STATES];
	Sound m_swing;
	State m_state;
	Vector2D m_direction;

};

