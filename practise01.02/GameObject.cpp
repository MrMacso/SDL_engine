#include "GameObject.h"

GameObject::GameObject()
{
	m_angle = 0.0f;
}
float GameObject::GetAngle() const
{
	return m_angle;
}
const std::string& GameObject::GetTag() const
{
	return m_tag;
}
const Vector2D& GameObject::GetSize() const
{
	return m_size;
}
const Vector2D& GameObject::GetPosition() const
{
	return m_position;
}
int GameObject::GetPositionX()
{
	return m_position.x;
}
int GameObject::GetPositionY()
{
	return m_position.y;
}
int GameObject::GetSizeX()
{
	return m_size.x;
}
int GameObject::GetSizeY()
{
	return m_size.y;
}
void GameObject::SetTag(const std::string& tag)
{
	m_tag = tag;
}
void GameObject::SetAngle(float angle)
{
	m_angle = angle;
}
void GameObject::SetSize(int width, int height)
{
	m_size = { width, height };
}
void GameObject::SetSize(const Vector2D& size)
{
	m_size = size;
}
void GameObject::SetPosition(int x, int y)
{
	m_position = { x, y };
}
void GameObject::SetPosition(const Vector2D& position)
{
	m_position = position;
}
void GameObject::SetPositionX(int position)
{
	m_position.x = position;
}
void GameObject::SetPositionY(int position)
{
	m_position.y = position;
}



