#pragma once
#define WIDTH 800
#define HEIGHT 600
#include "Paddle.h"
class Ball
{
private:
	float x;
	float y;
	float speedX;
	float speedY;
	int Score1, Score2;

public:
	Ball();
	float Angle(Paddle a);
	void Draw();
	void Delete();
	void Update();
	void Edges();
	void Reset();
	void checkPaddle(Paddle);
	int GetScore1();
	int GetScore2();
	float GetSpeedX();
	float GetSpeedY();
	float GetX();
	void SetScore();
};

