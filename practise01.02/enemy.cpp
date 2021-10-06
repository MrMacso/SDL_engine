#include "enemy.h"

enemy::enemy(Window& window)
{
	m_velocity = 1;
	m_position.x = 500;
	m_position.y = 300;
	
	m_facingDirection = LEFT;
	m_image.Load("assets/images/MonsterWalk.png", window);
	m_image.SetSpriteDimension(64, 64);
	m_image.SetImageDimension(8, 1, 256, 32);
	m_image.IsAnimated(true);
	m_image.SetAnimationVelocity(0.5f);
	m_image.IsAnimationLooping(true);

	
	SetDirection(1, 1);
	
	m_roar.Load("assets/music/roar.wav");
	m_roar.SetVolume(5);
}
enemy::~enemy()
{
	m_image.Unload();
}
int enemy::GetVelocity()
{
	return m_velocity;
}
Vector2D enemy::GetPosition()
{
	return m_position;
}
bool enemy::GetEnemyDead()
{
	return isEnemyDead;
}
void enemy::SetVelocity(int velocity)
{
	m_velocity = velocity;
}
void enemy::Behavior()
{
	if (isEnemyDead == false)
	{
		if (m_position.x == 1500) SetDirection(-1,0);
		if (m_position.x == -100) SetDirection(1, 0);
		if (m_position.y == 800) SetDirection(0, -1);
		if (m_position.y == -100) SetDirection(0, 1);
	}
}
void enemy::Respawn(Star& coin )
{
	if (isEnemyDead == true)
	{
		m_roar.Play(1);
		coin.SetPosition(m_position);
		m_position.x = rand() % 1400;
		m_position.y = rand() % 600;
		isEnemyDead = false;
	}
}

void enemy::SetDirection(int x, int y)
{
	m_direction.x += x;
	m_direction.y += y;
}
const BoxCollider& enemy::GetCollider() const
{
	return m_collider;
}


void enemy::Update(Player& player, Star& coin)
{
	if (m_collider.IsColliding(player.GetCollider()) && player.GetIsAttacking() == false)
	{
		player.ReduceHealth(10);
		std::cout << "I'M HITTING THE PLAYER" << std::endl;
	}
	if (m_collider.IsColliding(player.GetCollider()) && player.GetIsAttacking() == true)
	{
		
		isEnemyDead = true;
		std::cout << "I'M killing THE monster" << std::endl;
	}
	Behavior();
	Respawn(coin);
	m_collider.SetDimension(54, 34);
	m_collider.SetPosition(m_position.x + 5, m_position.y + 35);
	m_collider.Update();
	//======================================================================

	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);
	m_image.Update();
}


void enemy::Render(Window& window)
{
	if (m_facingDirection == RIGHT)
	{
		m_image.Render(m_position.x, m_position.y, m_angle, window, Sprite::NO_FLIP);
	}
	if (m_facingDirection == LEFT)
	{
		m_image.Render(m_position.x, m_position.y, m_angle, window, Sprite::HORZ_FLIP);
	}
}