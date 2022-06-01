#pragma once
#include "raylib.h"
struct Paddle
{
	float x, y;
	float speed; //we're going only in one direction
	float width, height;

	Rectangle GetRect()
	{
		return Rectangle{ x - width / 2, y - height / 2, 10, 100 };//return the size of the paddle
	}

	void Draw()
	{
		DrawRectangleRec(GetRect(), WHITE);
	}
	void resetRight()
	{
		x = GetScreenWidth() - 50;
		y = GetScreenHeight() / 2;

	}
	void resetLeft()
	{
		x = 50;
		y = GetScreenHeight() / 2 ;
	}
};