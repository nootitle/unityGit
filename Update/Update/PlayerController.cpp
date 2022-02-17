#include "PlayerController.h"
#include <iostream>
using namespace std;

void PlayerController::Init()
{
	cout << "Player Init" << endl;
}

void PlayerController::Update()
{
	cout << "Player Update" << endl;
}

void PlayerController::LateUpdate()
{
	cout << "Player LateUpdate" << endl;
}

void PlayerController::render()
{
	cout << "Player render" << endl;
}

void PlayerController::Destroy()
{
	cout << "Player Destroy" << endl;
}

PlayerController::PlayerController()
{
	cout << "Player" << endl;
}

PlayerController::~PlayerController()
{
	cout << "~Player" << endl;
}
