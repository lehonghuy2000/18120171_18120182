#include "Paddle.h"
void Paddle::Draw()
{
	setcolor(4);
	rectangle(left, top, right, bottom);
	setfillstyle(1, 4);
	floodfill(left+5, bottom-5, 4);
}
/*void Ball::Update()
{
	x = x + speedX;
	y = y + speedY;
}*/
Paddle::Paddle()
{

}
Paddle::Paddle(float x, float y)
{
	top = x;
	left = WIDTH / 2 - 100;
	right = WIDTH / 2 + 100;
	bottom = y;
}
void Paddle::Delete()
{
	setcolor(0);
	rectangle(left, top, right, bottom);
	setfillstyle(1, 0);
	floodfill(left+5, bottom-5, 0);
}
void Paddle::Move(float x)
{
	if (left+x >= 5 && left+x<=WIDTH-200)
	{
		left += x;
		right += x;
	}
}
int Paddle::isTop()
{
	if (top == 10)
		return 1;
	if (top == HEIGHT / 2 - 5)
		return 3;
	return 2;
}
float Paddle::Gettop()
{
	return top;
}
float Paddle::Getbottom()
{
	return bottom;
}
float Paddle::Getleft ()
{
	return left;
}
float Paddle::Getright()
{
	return right;
}

void Paddle::Reset() {
	left = WIDTH / 2 - 100;
	right = WIDTH / 2 + 100;
}