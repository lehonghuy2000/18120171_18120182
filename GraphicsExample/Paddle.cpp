#include "Paddle.h"

//Phương thức vẽ ván
void Paddle::Draw()
{
	setcolor(4); //Khởi tạo màu đỏ
	rectangle(left, top, right, bottom); // Vẽ hình chữ nhật rỗng theo toạ độ hiện tại
	setfillstyle(1, 4); //Lấy kiểu tô nền
	floodfill(left+5, bottom-5, 4); //Tô nền hình chữ nhật
}


Paddle::Paddle()
{

}

//Phương thức khởi tạo
Paddle::Paddle(float x, float y)
{
	top = x; //giới hạn trên của ván = x truyền vào
	left = WIDTH / 2 - 100; //giới hạn bên trái để ở giữa sân
	right = WIDTH / 2 + 100; //giới hạn bên phải để ở giữa sân
	bottom = y; //giới hạn bên trên = y truyền vào
}

//Phương thức xoá ván
void Paddle::Delete()
{
	setcolor(0);// khởi tạo màu đen để trùng với màu nền 
	rectangle(left, top, right, bottom); //vẽ hình chữ nhật tại vị trí hiện tại
	setfillstyle(1, 0);//Lấy kiểu tô nền
	floodfill(left+5, bottom-5, 0); //Tô nền hình chữ nhật
}

//Phương thức di chuyển ván
void Paddle::Move(float x)
{
	if (left+x >= 5 && left+x<=WIDTH-200)//Không cho ván vượt quá 2 biên dọc
	{
		left += x;//thay đổi giới hạn trái của ván với bước nhảy x
		right += x;// thay đổi giới hạn phải của ván với bước nhảy x
	}
}

//Phương thức kiểm tra ván có nằm trên hay không
int Paddle::isTop()
{
	if (top == 10)//ván nằm trên
		return 1;
	if (top == HEIGHT / 2 - 5)//ván nằm giữa trong mode nâng cao
		return 3;
	return 2;//ván nằm dưới
}

//Phương thức lấy tung độ của điểm trên bên trái
float Paddle::Gettop()
{
	return top;
}

//Phương thức lấy tung độ của điểm dưới bên phải
float Paddle::Getbottom()
{
	return bottom;
}

//Phương thức lấy hoành độ của điểm trên bên trái
float Paddle::Getleft ()
{
	return left;
}

//Phương thức lấy hoành độ của điểm dưới bên phải
float Paddle::Getright()
{
	return right;
}

// Phương thức đưa ván về vị trí ban đầu
void Paddle::Reset() {
	left = WIDTH / 2 - 100;
	right = WIDTH / 2 + 100;
}