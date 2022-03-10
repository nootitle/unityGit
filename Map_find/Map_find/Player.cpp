#include "Player.h"
#include "CursorManager.h"

void Player::Start()
{
	strKey = "Player";
	Info.Position = Vector3(10.0f, 10.0f, 0.0f);
	Info.Rotaiton = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 0.0f, 0.0f);
}

void Player::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		--Info.Position.y;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		++Info.Position.y;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		--Info.Position.x;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		++Info.Position.x;
	}

}

void Player::Render()
{
	CursorManager::SetCursorPosition(
		Info.Position.x,
		Info.Position.y);
	if(isActive)
		cout << "PP";
}

void Player::Release()
{
}

Player::Player()
{
}

Player::~Player()
{
}
