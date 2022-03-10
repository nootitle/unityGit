#pragma once
#include "headers.h"

class CursorManager
{
public:
	static void SetCursorPosition(Vector3 _Position)
	{
		COORD Pos = { (SHORT)_Position.x, (SHORT)_Position.y };

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	static void SetCursorPosition(float _x, float _y)
	{
		COORD Pos = { (SHORT)_x, (SHORT)_y };

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};