#pragma once
#define WIDTH 800
#define HEIGHT 600
#include"graphics.h"
class Paddle //Class quản lý ván 
{
private:
	float left; //hoành độ góc trên bên trái ván
	float top; //tung độ góc  trên bên trái
	float right; //hoành độ góc dưới bên phải ván
	float bottom; //tung độ góc dưới bên phải ván
public:
	Paddle(); // Phương thức khởi tạo ván
	Paddle(float, float); // Phương thức khởi tạo ván với vị trí top và bottom truyền vào
	void Draw(); //Phương thức vẽ ván tại theo các toạ độ hiện tại
	void Delete(); //Phương thức xoá ván tại theo các toạ độ hiện tại
	void Move(float); //Phương thức thay đổi toạ độ của ván
	int isTop(); //Phương thức kiểm tra ván nằm trên hay dưới
	float Gettop(); // Phương thức lấy tung độ góc trên bên trái ván
	float Getbottom(); // Phương thức lấy tung độ góc dưới bên trái ván
	float Getleft();// Phương thức lấy hoành độ góc trên bên trái ván 
	float Getright();// Phương thức lấy hoành độ góc dưới bên phải ván
	void Reset();// Phương thức đưa ván về vị trí ban đầu
};

