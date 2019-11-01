#include "Ball.h"
#include <time.h>
#include <cmath>

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}

void Ball::Draw()
{
	setcolor(15);
	circle(x, y,5);
	setfillstyle(1, 15);
	floodfill(x, y, 15);
}
void Ball::Update()
{
	x = x + speedX;
	y = y + speedY;
}
void Ball::Delete()
{
	setcolor(0);
	circle(x, y, 5);
	setfillstyle(1, 0);
	floodfill(x, y, 0);
}
void Ball::Reset()
{
	x = WIDTH/2;
	y = HEIGHT/2;
	srand((int)time(0));
	speedX = 6 * sin(random(135, 225) * atan2(0, -1) / 180);
	speedY= 6 * cos(random(135, 225) * atan2(0, -1) / 180);
	while (abs(speedY) <=5 && abs(speedX)<=5)
	{
		speedY = 6 * cos(random(135, 225) * atan2(0, -1) / 180);
		speedX = 6 * sin(random(135, 225) * atan2(0, -1) / 180);
	}
}
void Ball::Edges()
{
	if (x-10<0 || x>WIDTH - 5)
	{
		speedX *= -1;
	}
	if (y<0)
	{
		Score2++;
		Beep(523, 200);
		Reset();
	}
	if (y > HEIGHT - 15)
	{
		Score1++;
		Beep(523, 200);
		Reset();
	}
}
void Ball::checkPaddle(Paddle a)
{
	if (a.isTop()==1)
	{
		if ((y - 5) <= a.Getbottom()+5-speedY && (x - 5) >= a.Getleft()-10 && (x + 5) <= a.Getright()+10)
		{
			if (speedX < 0)
			{
				speedX += speedX / 10;
			}
			else
			{
				if (speedX > 0)
				{
						speedX += speedX / 10;
				}
			}
			if (speedY < 0)
			{
				speedY += speedY / 10;
			}
			else
			{
				if (speedY > 0)
				{
					speedY += speedY / 10;
				}
			}
			speedX = 6 * cos(Angle(a));
			speedY *= -1;
		}
		else
		{
			if ((x + 5) >= a.Getleft() - 15 && (x - 5) <= a.Getright() + 15 && (y - 5) >= a.Gettop() && (y + 5) <= a.Getbottom())
			{
				if (speedX < 0)
				{
					speedX += speedX / 10;
				}
				else
				{
					if (speedX > 0)
					{
						speedX += speedX / 10;
					}
				}
				if (speedY < 0)
				{
					speedY += speedY / 10;
				}
				else
				{
					if (speedY > 0)
					{
						speedY += speedY / 10;
					}
				}
				speedX = 6 * cos(Angle(a));
				speedY *= -1;
			}
		}
	}
	else
	{
		if (a.isTop() == 2)
		{
			if ((y + 5) >= a.Gettop() - 5 - speedY && (x - 5) >= a.Getleft() - 10 && (x + 5) <= a.Getright() + 10)
			{
				if (speedX < 0)
				{
					speedX += speedX / 10;
				}
				else
				{
					if (speedX > 0)
					{
						speedX += speedX / 10;
					}
				}
				if (speedY < 0)
				{
					speedY += speedY / 10;
				}
				else
				{
					if (speedY > 0)
					{
						speedY += speedY / 10;
					}
				}
				//speedY *= -1;
				speedX = 6 * cos(Angle(a));
				speedY *= -1;
			}
			else
			{
				if ((x + 5) >= a.Getleft() - 15 && (x - 5) <= a.Getright() + 15 && (y - 5) >= a.Gettop() && (y + 5) <= a.Getbottom())
				{
					if (speedX < 0)
					{
						speedX += speedX / 10;
					}
					else
					{
						if (speedX > 0)
						{
							speedX += speedX / 10;
						}
					}
					if (speedY < 0)
					{
						speedY += speedY / 10;
					}
					else
					{
						if (speedY > 0)
						{
							speedY += speedY / 10;
						}
					}
					/*speedX *= -1;
					speedY *= -1;*/
					speedX = 6 * cos(Angle(a));
					speedY *= -1;
				}
			}
		}
		else
		{
			if (a.isTop() == 3)
			{
				if (y < a.Gettop())
				{
					bool TouchTop = (y + 5) >= a.Gettop() - 5 - speedY && (x - 5) >= a.Getleft() - 10 && (x + 5) <= a.Getright() + 10;
					if (TouchTop)
					{
						speedX = 6 * cos(Angle(a));
						speedY *= -1;
					}
				}
				else
				{
					if (y > a.Getbottom())
					{
						bool TouchBottom = (y - 5) <= a.Getbottom() + 5 - speedY && (x - 5) >= a.Getleft() - 10 && (x + 5) <= a.Getright() + 10;
						if (TouchBottom)
						{
							speedX = 6 * cos(Angle(a));
							speedY *= -1;
						}
					}
					else
					{
						bool TouchRL = (x + 5) >= a.Getleft() - 15 && (x - 5) <= a.Getright() + 15 && (y - 5) >= a.Gettop() && (y + 5) <= a.Getbottom();
						if (TouchRL)
						{
							speedX = 6 * cos(Angle(a));
							speedY *= -1;
						}
					}
				}
			}
		}
	}
}
float Ball::Angle(Paddle a)
{
	int offset = (x + 5 - (a.Getleft() + 100)) / (10 + 5);
	float phi = 0.25 * 3.141 * (2 * offset - 1);
	if (x == a.Getleft() + 100)
	{
		phi = atan2(0, -1) / 2;
	}
	return phi;
}
Ball::Ball()
{
	Reset();
	Score1 = 0;
	Score2 = 0;
}
int Ball::GetScore1()
{
	return Score1;
}
int Ball::GetScore2()
{
	return Score2;
}
float Ball::GetSpeedX()
{
	return speedX;
}
float Ball::GetSpeedY()
{
	return speedY;
}
float Ball::GetX() {
	return x;
}

void Ball::SetScore() {
	Score1 = 0;
	Score2 = 0;
}