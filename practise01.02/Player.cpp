#include "Player.h"


Player::Player(Window& window)
{
	m_velocity = 0;
	m_health = 1000;
	m_position.x = 753;
	m_position.y = 350;
	m_isAttacking = false;
	m_image[Idle].Load("assets/images/FightLightBanditLeft.png", window);
	m_image[Run].Load("assets/images/LeftRunLightBandit.png", window);
	m_image[Attack].Load("assets/images/AttackLeftLightBandit.png", window);
	m_image[Hurt].Load("assets/images/FightLightBandit.png", window);
	m_image[Die].Load("assets/images/FightLightBandit.png", window);

	for (int i = 0; i < Total_states; i++)
	{
		m_image[i].SetSpriteDimension(132, 120);

		if (i == Idle)
		{
			m_image[i].SetImageDimension(4, 1, 192, 48);
		}
		else
		{
			m_image[i].SetImageDimension(8, 1, 384, 48);
		}
		m_image[i].IsAnimated(true);
		m_image[i].SetAnimationVelocity(0.5f);

		if ( i == Die)
		{
			m_image[i].IsAnimationLooping(true);
		}
		else
		{
			m_image[i].IsAnimationLooping(true);
		}
	}
}
Player::~Player()
{
	m_image[m_state].Unload();
}
int Player::GetVelocity()
{
	return m_velocity;
}
int Player::GetHealth()
{
	return m_health;
}
int Player::GetCoin()
{
	return m_coin;
}
void Player::SetHealth(int health)
{
	m_health = health;
}
void Player::AddCoin(int coin)
{
	m_coin = m_coin + coin;
}
void Player::ReduceHealth(int damage)
{
	m_health = m_health - damage;
}
void Player::IncreaseHealth(int heal)
{
	m_health = m_health + heal;
}
void Player::CheckHealth()
{
	if (m_health < 0)
	{
		m_health = 0;
	}
	if (m_health > 1000)
	{
		m_health = 1000;
	}
}
void Player::SetState(State state)
{
	m_state = state;
}
void Player::SetVelocity(int velocity)
{
	m_velocity = velocity;
}
void Player::SetIsAttacking(bool attack)
{
	m_isAttacking = attack;
}
bool Player::GetIsAttacking()
{
	return m_isAttacking;
}
void Player::AttackCollider()
{
	if (m_isAttacking == true)
	{
		m_collider.SetDimension(90, 90);
		m_collider.SetPosition(m_position.x, m_position.y + 30);
	}
	else
	{
		m_collider.SetDimension(45, 90);
		m_collider.SetPosition(m_position.x + 35, m_position.y + 30);
	}
}
const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}

void Player::Update(Input& input)
{
	if (input.GetKeyDown() == SDLK_a)
	{
		m_direction.x = -1;
		m_direction.y = 0;
		m_facingDirection = Left;
		SetState(Run);

	}
	else if (input.GetKeyDown() == SDLK_d)
	{

		m_direction.x = 1;
		m_direction.y = 0;
		m_facingDirection = Right;
		SetState(Run);

	}
	else if (input.GetKeyDown() == SDLK_w)
	{
		m_direction.x = 0;
		m_direction.y = -1;
		SetState(Run);
	}
	else if (input.GetKeyDown() == SDLK_s)
	{
		m_direction.x = 0;
		m_direction.y = 1;
		SetState(Run);
	}
	else if (input.GetKeyDown() == SDLK_e)
	{
		IncreaseHealth(10);
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		SetState(Idle);
		m_isAttacking = false;
	}
	if (input.GetKeyDown() == SDLK_q)
	{
		SetState(Attack);
		m_isAttacking = true;
		AttackCollider();
	}
	//======================================================================
	CheckHealth();
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);

	m_collider.SetDimension(45, 90);
	m_collider.SetPosition(m_position.x +35, m_position.y + 30);
	m_collider.Update();
	m_image[m_state].Update();
}

void Player::Render(Window& window)
{
	if (m_facingDirection == Left)
	{
		m_image[m_state].Render(m_position.x, m_position.y, m_angle, window, Sprite::NO_FLIP);
	}
	if(m_facingDirection == Right)
	{
		m_image[m_state].Render(m_position.x, m_position.y, m_angle, window, Sprite::HORZ_FLIP);
	}
}
