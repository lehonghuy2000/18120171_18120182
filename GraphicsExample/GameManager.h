#pragma once
#include "Ball.h"
class GameManager
{
	Ball a;
	Paddle b;
	Paddle c;
	Paddle e;
	bool win;
public:
	GameManager();
	void RunPvP();
	void RunPvC();
	void RunLevelUp();
	void InputPvP(char s);
	void InputPvC(char s);
	void isWin();
	void TuChoi(int &x);
	void drawButton(int left, int  top, int right, int bottom, int test, char s[]);
	void Reset();
	void LevelUp();
	void Menu();
};

