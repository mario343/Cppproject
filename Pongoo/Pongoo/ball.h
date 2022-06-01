#pragma once
//struct of ball
struct Ball
{
	float x, y;
	float speedX, speedY;
	float radius;


	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, WHITE);
	}
	void resetBallLeft()
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		speedX = -250;
		speedY = 250;
	}
	void resetBallRight()
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		speedX = 250;
		speedY = 250;
	}
	void endGameBall() {
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;
		speedX = 0;
		speedY = 0;

	}

	//friend struct that will render a circle to cover the white one after the game 
	friend struct StaticBall;
	//friend void DrawCircle(StaticBall&);
};



struct StaticBall
{
	friend struct Ball;
	float x, y;
	float speedX, speedY;
	float radius;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, BLACK);
	}
	void center() {
		x = GetScreenWidth() / 2.0f;
		y = GetScreenHeight() / 2.0f;
		radius = 5;
		speedX = 0;
		speedY = 0;
	}
};