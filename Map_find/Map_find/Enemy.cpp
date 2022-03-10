#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy()
{
	
}

Enemy::Enemy(int value)
{
	iNumber = value;
}

Enemy::~Enemy()
{
	Release();
}

void Enemy::Start()
{
	strKey = "Enemy";
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotaiton = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 0.0f, 0.0f);
}

void Enemy::Update()
{
}

void Enemy::Render()
{
	CursorManager::SetCursorPosition(
		Info.Position.x,
		Info.Position.y);
	if (isActive)
		cout << "EE";
}

void Enemy::Release()
{
}
