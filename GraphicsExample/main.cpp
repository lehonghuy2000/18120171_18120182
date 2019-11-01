/*#include "conio.h"
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "stdlib.h"

using namespace std;
Ball a;
Paddle b(10, 20);
Paddle c(HEIGHT - 30, HEIGHT - 20);

void Input(char s)
{
	
	if (s == 'a')
	{
		b.Move(-20);
	}
	else
	{
		if (s == 'd')
		{
			b.Move(20);
		}
	}
	if (s =='j')
	{
		c.Move(-20);
	}
	else
	{
		if (s == 'l')
		{
			c.Move(20);
		}
	}
}
int main( )
{
	char s;
    initwindow(WIDTH+200, HEIGHT);

	a.Draw();
	b.Draw();
	c.Draw();
	while (1)
	{
		char score1[50];
		char score2[50];
		setcolor(6);
		circle(WIDTH / 2, HEIGHT / 2, 30);
		line(5, 5, WIDTH,5);
		line(5, HEIGHT-15, WIDTH, HEIGHT-15);
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);
		line(WIDTH, 5, WIDTH, HEIGHT-15);
		line(5, 5, 5, HEIGHT - 15);
		itoa(a.GetScore1(), score1, 10);
		itoa(a.GetScore2(), score2, 10);
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);
		outtextxy(WIDTH + 100, 3*HEIGHT / 4, score2);
		if (kbhit())
		{
			s = getch();
			b.Delete();
			c.Delete();
			Input(s);
			b.Draw();
			c.Draw();
		}
		a.checkPaddle(b);
		a.checkPaddle(c);
		delay(25);
		a.Delete();
		a.Update();
		a.Edges();
		a.Draw();
	}*/
#include "GameManager.h"

int main()
{
	GameManager a;
	a.Menu();
	getchar();
}