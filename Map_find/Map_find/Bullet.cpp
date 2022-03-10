#include "Bullet.h"
#include "CursorManager.h"

void Bullet::Start()
{
	strKey = "Bullet";
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotaiton = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
}

void Bullet::Update()
{
}

void Bullet::Render()
{
	CursorManager::SetCursorPosition(
		Info.Position.x,
		Info.Position.y);
	if (isActive)
		cout << "B";
}

void Bullet::Release()
{
}

Bullet::Bullet()
{
}

Bullet::Bullet(int value)
{
	iNumber = value;
}

Bullet::~Bullet()
{
	Release();
}
