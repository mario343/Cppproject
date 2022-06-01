#include "raylib.h"
#include "ball.h"
#include "paddle.h"

//supposed to handle the storage value
typedef enum {
	STORAGE_POSITION_SCORE_LEFT = 0,
	STORAGE_POSITION_SCORE_RIGHT = 0
} StorageData;


int main()

{   //make the window 
	InitWindow(800, 600, "pong");

	//setting the FPS rate exactly as the monitor hz 
	SetWindowState(FLAG_VSYNC_HINT);

	//making the ball object
	Ball ball;
	ball.x= GetScreenWidth()/2.0f;
	ball.y = GetScreenHeight()/2.0f;
	ball.radius =5;
	ball.speedX = 200;
	ball.speedY = 200;

	StaticBall staticBall;
	staticBall.x = 1000;
	staticBall.y = 1000;
	staticBall.radius = 0;
	staticBall.speedX = 0;
	staticBall.speedY = 0;
	
	//making the left paddle object
	Paddle leftPaddle;
	leftPaddle.x = 50;
	leftPaddle.y = GetScreenHeight() / 2 ;
	leftPaddle.width = 10;
	leftPaddle.height = 100;
	leftPaddle.speed = 600;

	//making the right paddle object
	Paddle rightPaddle;
	rightPaddle.x = GetScreenWidth() - 50;
	rightPaddle.y = GetScreenHeight() / 2;
	rightPaddle.width = 10;
	rightPaddle.height = 100;
	rightPaddle.speed = 600;

	
	const char* winnerTxt = nullptr;
	int leftScore = 0;
	int rightScore = 0;
	

	while (!WindowShouldClose())
	{
		//moving the ball, ballspeed* as a variable gives us way more faster  ball due to the small number of Frame
		ball.x += ball.speedX * GetFrameTime();
		ball.y += ball.speedY *GetFrameTime();

		//we prevent the ball from going off the screen at the top 
		if (ball.y < 0)
		{

			ball.y = 0;
			ball.speedY *= -1;

		}

		// =|= at the bottom
		if (ball.y > GetScreenHeight())
		{

			ball.y = GetScreenHeight(); //preventing from the bug 
			ball.speedY *= -1;

		}

		
		

		//if key pressed the LEFT paddle goes up
		if (IsKeyDown(KEY_UP))
		{
			leftPaddle.y -= leftPaddle.speed * GetFrameTime();
		}

		// =|= down
		if (IsKeyDown(KEY_DOWN))
		{
			leftPaddle.y += leftPaddle.speed * GetFrameTime();
		}
		
		//if key pressed the RIGHT paddle goes up
		if (IsKeyDown(KEY_S))
		{
			rightPaddle.y += rightPaddle.speed * GetFrameTime();
		}

		//=|= down
		if (IsKeyDown(KEY_W))
		{
			rightPaddle.y -= rightPaddle.speed * GetFrameTime();
		}

		//we prevent the LEFT paddle from going off the screen at the top 
		if ((leftPaddle.y + 50) < 100)
		{
			leftPaddle.y = 50;
		}

		// =|= bottom 
		if ((leftPaddle.y + 50) > GetScreenHeight())
		{
			leftPaddle.y = GetScreenHeight() - 50;
		}

		//we prevent the RIGHT paddle from going off the screen at the top
		if ((rightPaddle.y + 50) < 100)
		{
			rightPaddle.y = 50;
		}

		// =|= bottom 
		if ((rightPaddle.y + 50) > GetScreenHeight())
		{
			rightPaddle.y = GetScreenHeight() - 50;
		}

		//collision function between the ball and paddle, using the vector to track the center of the  ball, for the right paddle
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, rightPaddle.GetRect()))
		{
			//if statement is for the case when we hit the ball with the top size of the ball
			if (ball.speedX > 0)
			{
				ball.speedX *= -1.10f; // is for ball speeding up
				ball.speedY = ((ball.y - rightPaddle.y) / (rightPaddle.height / 2) * -ball.speedX); //if the ball is on the top of the paddle then it's gonna bounce of it and go up/down
			}
		}

		// =|= for the left paddle
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, leftPaddle.GetRect()))
		{
			
			if (ball.speedX < 0)
			{
				ball.speedX *= -1.10f; 
				ball.speedY = ((ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX);
			}
		}

		//taking the winer
		//right one
		if (ball.x < 0)
		{
			
			rightScore+=1;
			ball.resetBallRight();
		}

		//left one
		if (ball.x > GetScreenWidth())
		{
			
			leftScore+=1;
			ball.resetBallLeft();
		}

		if ((leftScore > rightScore) && leftScore== 5)
		{
			 winnerTxt = "left wins!";
			ball.endGameBall();
			staticBall.center();
		}
		if ((rightScore > leftScore) && rightScore == 5)
		{
			winnerTxt = "right wins!";
			ball.endGameBall();
			staticBall.center();
		}

		//reseting the game once it's over
		if (winnerTxt && IsKeyPressed(KEY_ENTER))
		{
			winnerTxt = nullptr;
			//SaveStorageValue(STORAGE_POSITION_SCORE_RIGHT, rightScore);
			//SaveStorageValue(STORAGE_POSITION_SCORE_LEFT, leftScore);
			ball.resetBallRight();
			
			leftScore = 0;
			rightScore = 0;
			leftPaddle.resetLeft();
			rightPaddle.resetRight();
			
		}

		BeginDrawing();
		ClearBackground(BLACK);

		//draw circle that appears exactly at the centre of the screen, size in px of the circle (by the varialbe- ballY and ballX) and the color
		ball.Draw();
		leftPaddle.Draw();
		rightPaddle.Draw();
		staticBall.Draw();

		if (!winnerTxt)
		{
			
			DrawText(TextFormat("%i", leftScore), 250, 50, 50, WHITE);
			DrawText(TextFormat("%i", rightScore), 550, 50, 50, WHITE);
		}
		else
		{
			DrawText(winnerTxt, 300, GetScreenHeight() / 2 - 30, 60, SKYBLUE);
			DrawText(TextFormat("%i", leftScore), 250, 50, 50, WHITE);
			DrawText(TextFormat("%i", rightScore), 550, 50, 50, WHITE);
		}

		

		//shows the FPS rate, 30x- to the right 30y- to the down
		DrawFPS(700, 30);

		//handles the drawings, eg. closing, minimalizing game etc
		EndDrawing();

	}
	CloseWindow();
	return 0;
}