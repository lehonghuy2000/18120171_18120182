#include "Ball.h"
#include <time.h>
#include <cmath>
// Đây là hàm phát sinh 1 số ngẫu nhiên từ minN đến maxN
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}
// Đây là hàm vẽ trái banh
void Ball::Draw()
{
	setcolor(15); // Thiết lập màu sắc trái banh
	circle(x, y,5); // Vẽ hình tròn bán kính bằng 5
	setfillstyle(1, 15); // Chọn mẫu tô và màu tô
	floodfill(x, y, 15); // Tô màu hình tròn vừa vẽ
}
// Đây là hàm thay đổi vị trí trái banh
void Ball::Update()
{
	x = x + speedX;
	y = y + speedY;
}
// Đây là hàm xoá trái banh
void Ball::Delete()
{
	setcolor(0); // Thiết lập màu sắc trùng với màu nền
	circle(x, y, 5);
	setfillstyle(1, 0);
	floodfill(x, y, 0);
}
// Đây là hàm thiết lập trạng thái ban đầu của trái banh
void Ball::Reset()
{
	x = WIDTH/2;
	y = HEIGHT/2;
	srand((int)time(0));
	speedX = 6 * sin(random(135, 225) * atan2(0, -1) / 180); //Thiết lập ngẫu nhiên giá trị của tốc độ theo trục hoành
	speedY= 6 * cos(random(135, 225) * atan2(0, -1) / 180);//Thiết lập ngẫu nhiên giá trị của tốc độ theo trục hoành
	while (abs(speedY) <=5 && abs(speedX)<=5) //Kiếm tra điều kiện để tốc độ không quá chậm
	{
		speedY = 6 * cos(random(135, 225) * atan2(0, -1) / 180);
		speedX = 6 * sin(random(135, 225) * atan2(0, -1) / 180);
	}
}
// Đây là hàm xử lý khi chạm vào các cạnh sân
void Ball::Edges()
{
	if (x-10<0 || x>WIDTH - 5) // Nếu chạm vào hai biên ngang
	{
		speedX *= -1; //Đổi chiều chuyển động
	}
	if (y<0) // Nếu chạm vào cạnh trên của sân
	{
		Score2++; // Nâng điểm cho người chơi 2
		Beep(523, 200); // Phát ra tiếng beep
		Reset(); // Khôi phục trạng thái ban đầu của trái banh
	}
	if (y > HEIGHT - 15) // Nếu chạm vào cạnh dưới sân
	{
		Score1++; // Nâng điểm cho người chơi 1
		Beep(523, 200); // Phát ra tiếng beep
		Reset(); // Khôi phục trạng thái ban đầu của trái banh
	}
}
//Đây là hàm xử lý khi chạm thanh trượt
void Ball::checkPaddle(Paddle a)
{
	if (a.isTop()==1) // Kiếm tra có phải thanh trượt trên cùng
	{
		if ((y - 5) <= a.Getbottom()+5-speedY && (x - 5) >= a.Getleft()-10 && (x + 5) <= a.Getright()+10) // kiểm tra có chạm vào thanh trượt
		{ // tăng tốc độ banh 10%
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
				speedX = 6 * cos(Angle(a)); // Đối hướng của banh
				speedY *= -1;
			}
		}
	}
	else
	{
		if (a.isTop() == 2) // Kiểm tra có phải thanh trượt dưới không
		{
			if ((y + 5) >= a.Gettop() - 5 - speedY && (x - 5) >= a.Getleft() - 10 && (x + 5) <= a.Getright() + 10) // Kiếm tra có chạm thanh trượt
			{
				// Tăng tốc 10%
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
				speedX = 6 * cos(Angle(a)); // Đổi hướng banh
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
					speedX = 6 * cos(Angle(a)); // Đổi hướng banh
					speedY *= -1;
				}
			}
		}
		else
		{
			if (a.isTop() == 3)// kiếm tra có phải là thanh trượt ở giữa màn hình không
			{
				if (y < a.Gettop()) // kiếm tra vị trí banh đang ở đâu
				{
					bool TouchTop = (y + 5) >= a.Gettop() - 5 - speedY && (x - 5) >= a.Getleft() - 10 && (x + 5) <= a.Getright() + 10;
					if (TouchTop) // Kiếm tra có đụng ở phía trên 
					{
						speedX = 6 * cos(Angle(a)); //Đổi hướng banh
						speedY *= -1;
					}
				}
				else
				{
					if (y > a.Getbottom()) // Kiếm tra vị trí banh
					{
						bool TouchBottom = (y - 5) <= a.Getbottom() + 5 - speedY && (x - 5) >= a.Getleft() - 10 && (x + 5) <= a.Getright() + 10;
						if (TouchBottom) // Kiếm tra có đụng phía dưới
						{
							speedX = 6 * cos(Angle(a)); // Đổi hướng banh
							speedY *= -1;
						}
					}
					else
					{
						bool TouchRL = (x + 5) >= a.Getleft() - 15 && (x - 5) <= a.Getright() + 15 && (y - 5) >= a.Gettop() && (y + 5) <= a.Getbottom();
						if (TouchRL) // Kiếm tra đụng hai bên
						{
							speedX = 6 * cos(Angle(a)); // Đổi hướng banh
							speedY *= -1;
						}
					}
				}
			}
		}
	}
}
// đây làm hàm tính góc để đối hướng banh
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
// đây là hàm khởi tạo banh
Ball::Ball()
{
	Reset();
	Score1 = 0;
	Score2 = 0;
}
int Ball::GetScore1() // lấy điểm người chơi 1
{
	return Score1;
}
int Ball::GetScore2() //lấy điểm người chơi 2
{
	return Score2;
}
float Ball::GetSpeedX() // lấy tốc độ theo trục hoành
{
	return speedX;
}
float Ball::GetSpeedY() // lấy tốc độ theo trục tung
{
	return speedY;
}
float Ball::GetX() { // lấy hoành độ banh
	return x;
}

void Ball::SetScore() { //Thiết lập điểm
	Score1 = 0;
	Score2 = 0;
}