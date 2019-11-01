#include "GameManager.h"
GameManager::GameManager()
{
	Paddle a(10, 20);
	Paddle d(HEIGHT - 30, HEIGHT - 20);
	Paddle f(HEIGHT / 2 - 5, HEIGHT / 2 + 5);
	b = a;
	c = d;
	e = f;
	win = false;
	
}
void GameManager::InputPvP(char s)
{
	if (s == 'a')
	{
		b.Move(-10);
	}
	else
	{
		if (s == 'd')
		{
			b.Move(10);
		}
	}
	if (s == 'j')
	{
		c.Move(-10);
	}
	else
	{
		if (s == 'l')
		{
			c.Move(10);
		}
	}
}

void GameManager::InputPvC(char s)
{
	if (s == 'j')
	{
		c.Move(-10);
	}
	else
	{
		if (s == 'l')
		{
			c.Move(10);
		}
	}
}

void GameManager::isWin()
{
	if (a.GetScore1() == 5)
	{
		settextstyle(0,0,15);
		setcolor(9);
		settextjustify(1, 2);
		outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Nguoi choi 1 Chien Thang");
		delay(3000);
		win = true;
	}
	else
	{
		if (a.GetScore2() == 5)
		{
			settextstyle(0, 0, 15);
			setcolor(9);
			settextjustify(1, 2);
			outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Nguoi choi 2 Chien Thang");
			delay(3000);
			win = true;
		}
	}
}
void GameManager::TuChoi(int &x)
{
	if (a.GetX()-10 < b.Getleft()) {
		b.Move(-x);
	}
	else if (a.GetX()+10>b.Getright()) {
		b.Move(x);
	}
}
void GameManager::RunLevelUp()
{
	char s;
	//initwindow(WIDTH + 200, HEIGHT);
	a.Draw();
	b.Draw();
	c.Draw();
	while (!win)
	{
		int x = 10;
		int t1 = a.GetScore1();
		int t2 = a.GetScore2();
		char score1[50];
		char score2[50];
		setcolor(6);
		circle(WIDTH / 2, HEIGHT / 2, 30);
		line(5, 5, WIDTH, 5);
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);
		line(WIDTH, 5, WIDTH, HEIGHT - 15);
		line(5, 5, 5, HEIGHT - 15);
		b.Delete();
		TuChoi(x);
		b.Draw();
		if (kbhit())
		{
			s = getch();
			//b.Delete();
			c.Delete();
			InputPvC(s);
			//b.Draw();
			c.Draw();
		}
		a.checkPaddle(b);
		a.checkPaddle(c);
		LevelUp();
		delay(25);
		a.Delete();
		a.Update();
		a.Edges();
		if (t1 != a.GetScore1() || t2 != a.GetScore2())
		{
			e.Delete();
		}
		setcolor(6);
		itoa(a.GetScore1(), score1, 10);
		itoa(a.GetScore2(), score2, 10);
		settextstyle(0, 0, 30);
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);
		settextstyle(0, 0, 30);
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);
		isWin();
		a.Draw();
	}
}
void GameManager::RunPvC()
{

	char s;
	//initwindow(WIDTH + 200, HEIGHT);
	a.Draw();
	b.Draw();
	c.Draw();
	while (!win)
	{
		int x = 10;
		char score1[50];
		char score2[50];
		setcolor(6);
		circle(WIDTH / 2, HEIGHT / 2, 30);
		line(5, 5, WIDTH, 5);
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);
		line(WIDTH, 5, WIDTH, HEIGHT - 15);
		line(5, 5, 5, HEIGHT - 15);
		b.Delete();
		TuChoi(x);
		b.Draw();
		if (kbhit())
		{
			s = getch();
			//b.Delete();
			c.Delete();
			InputPvC(s);
			//b.Draw();
			c.Draw();
		}
		a.checkPaddle(b);
		a.checkPaddle(c);
		delay(25);
		a.Delete();
		a.Update();
		a.Edges();
		setcolor(6);
		itoa(a.GetScore1(), score1, 10);
		itoa(a.GetScore2(), score2, 10);
		settextstyle(0, 0, 30);
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);
		settextstyle(0, 0, 30);
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);
		isWin();
		a.Draw();
	}
}

void GameManager::RunPvP()
{
	char s;
	//initwindow(WIDTH + 200, HEIGHT);
	a.Draw();
	b.Draw();
	c.Draw();
	while (!win)
	{
		int x = 10;
		char score1[50];
		char score2[50];
		setcolor(6);
		circle(WIDTH / 2, HEIGHT / 2, 30);
		line(5, 5, WIDTH, 5);
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);
		line(WIDTH, 5, WIDTH, HEIGHT - 15);
		line(5, 5, 5, HEIGHT - 15);
		if (kbhit())
		{
			s = getch();
			b.Delete();
			c.Delete();
			InputPvP(s);
			b.Draw();
			c.Draw();
		}
		a.checkPaddle(b);
		a.checkPaddle(c);
		delay(25);
		a.Delete();
		a.Update();
		a.Edges();
		setcolor(6);
		itoa(a.GetScore1(), score1, 10);
		itoa(a.GetScore2(), score2, 10);
		settextstyle(0, 0, 13);
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);
		isWin();
		a.Draw();
	}
}

void GameManager::drawButton(int left,int  top, int right, int bottom, int test, char s[]) {
	if (test == 1) {
		setcolor(4);
		rectangle(left, top, right, bottom);
		setcolor(14);
		settextstyle(0, 0, 13);
		moveto(left + 150, top + 15);
		settextjustify(1, 2);
		outtextxy(left + 150, top + 15, s);
	}
	else {
		setcolor(14);
		rectangle(left, top, right, bottom);
		setcolor(4);
		settextstyle(0, 0, 13);
		moveto(left + 150, top + 15);
		settextjustify(1, 2);
		outtextxy(left + 150, top + 15, s);
	}
}

void GameManager::Menu() 
{
	int left = 1000/ 2 - 150;
	int right =  1000 / 2 + 150;
	int top = 100;
	int bottom = 150;
	int x, y;
	int quit = 0;
	initwindow(WIDTH + 200, HEIGHT);
	drawButton(left, top, right, bottom, 0, "Player vs Player");
	drawButton(left, top + 100, right, bottom + 100, 0,"Player vs Computer");
	drawButton(left, top + 200, right, bottom + 200, 0,"Play Hard");
	drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
	while (!quit) {
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, x, y);
			if (x >= left && x <= right && y >= top && y <= bottom) {
				drawButton(left, top, right, bottom, 1, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 0, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 100 && y <= bottom + 100) {
				drawButton(left, top, right, bottom, 0, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 1, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 0, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 200 && y <= bottom + 200) {
				drawButton(left, top, right, bottom, 0, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 1, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 300 && y <= bottom + 300)
			{
				drawButton(left, top, right, bottom, 0, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 0, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 1, "Quit Game");
			}
			else { 
				drawButton(left, top, right, bottom, 0, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 0, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (x >= left && x <= right && y >= top && y <= bottom) {
				cleardevice();
				Reset();
				RunPvP();
			}
			else if (x >= left && x <= right && y >= top + 100 && y <= bottom + 100) {
				cleardevice();
				Reset();
				RunPvC();
			}
			else if (x >= left && x <= right && y >= top + 200 && y <= bottom + 200) {
				cleardevice();
				Reset();
				RunLevelUp();
			}
			else if (x >= left && x <= right && y >= top + 300 && y <= bottom + 300) {
				exit(0);
			}
			cleardevice();
		}
	}
}

void GameManager::Reset()
{
	win = 0;
	a.SetScore();
	b.Reset();
	c.Reset();
}
void GameManager::LevelUp()
{
	if (abs(a.GetSpeedY()) > 8)
	{
		e.Draw();
		a.checkPaddle(e);
	}
}