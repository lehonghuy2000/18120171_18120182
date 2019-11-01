#pragma once
#define WIDTH 800
#define HEIGHT 600
#include"graphics.h"
class Paddle
{
private:
	float left;
	float top;
	float right;
	float bottom;
public:
	Paddle();
	Paddle(float, float);
	void Draw();
	void Delete();
	void Move(float);
	int isTop();
	float Gettop();
	float Getbottom();
	float Getleft();
	float Getright();
	void Reset();
};

