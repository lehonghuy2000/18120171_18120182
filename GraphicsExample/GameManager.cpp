#include "GameManager.h"

//Phương thức khởi tạo
GameManager::GameManager()
{
	Paddle a(10, 20);//khởi tạo ván trên với top = 10 và bottom = 20
	Paddle d(HEIGHT - 30, HEIGHT - 20);//Khởi tạo ván dưới với top = chiều cao cửa số - 30 và bottom = chiều cao cửa số - 20
	Paddle f(HEIGHT / 2 - 5, HEIGHT / 2 + 5);//Khởi tạo ván ở giữa sân
	b = a;
	c = d;
	e = f;
	win = false;//khởi tạo biến win = false để game tiếp tục
	
}

//Phương thức lấy dữ liệu từ bàn phím mode 2 người chơi
void GameManager::InputPvP(char s)
{
	if (s == 'a' || s == 'A')//Dữ liệu nhập vào là a
	{
		b.Move(-10); //Di chuyển ván trên sang trái 10 pixel
	}
	else
	{
		if (s == 'd' || s == 'D')//Dữ liệu nhập vào là d
		{
			b.Move(10);//Di chuyển ván trên sang phải 10 pixel
		}
	}
	if (s == 'j' || s == 'J')//Dữ liệu nhập vào là j
	{
		c.Move(-10);//Di chuyển ván dưới sang trái 10 pixel
	}
	else
	{
		if (s == 'l' || s == 'L')//Dữ liệu nhập vào là l
		{
			c.Move(10);//Di chuyển ván dưới sang phải 10 pixel
		}
	}
}

//Phương thức lấy dữ liệu từ bàn phím mode chơi với máy
void GameManager::InputPvC(char s)
{
	if (s == 'j' || s == 'J')//Dữ liệu nhập vào là j
	{
		c.Move(-10);//Di chuyển ván dưới sang trái 10 pixel
	}
	else
	{
		if (s == 'l' || s == 'L')//Dữ liệu nhập vào là 'l'
		{
			c.Move(10);//Di chuyển ván dưới sang phải 10 pixel
		}
	}
}

//Phương thức kiểm tra đã có người chiến thắng hay chưa
void GameManager::isWin()
{
	if (a.GetScore1() == 5)//Nếu điểm người chơi 1 bằng 5
	{
		settextstyle(0,0,15);//Set kiểu chữ
		setcolor(9);//Set màu chữ thành xanh
		settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
		outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Nguoi choi 1 Chien Thang");//Xuât chuỗi ra màn hình ở giữa cửa sổ
		delay(3000);//Dừng Game trong 3 giây
		win = true;//Set biến win = true để game kết thúc
	}
	else
	{
		if (a.GetScore2() == 5)//Nếu điểm người chơi 1 bằng 5
		{
			settextstyle(0, 0, 15);//Set kiểu chữ
			setcolor(9);//Set màu chữ thành xanh
			settextjustify(1, 2);//Set cách viết chữ từ giữa sang 2 bên
			outtextxy(WIDTH / 2, HEIGHT / 2 - 17, "Nguoi choi 2 Chien Thang");//Xuât chuỗi ra màn hình ở giữa cửa sổ
			delay(3000);//Dừng Game trong 3 giây
			win = true;//Set biến win = true để game kết thúc
		}
	}
}

//Phương thức tư di chuyển ván
void GameManager::TuChoi(int &x)
{
	if (a.GetX()-10 < b.Getleft()) {//Nếu vị trí của bóng nằm ngoài giới hạn trái của ván tự động
		b.Move(-x);//Di chuyển sang trái
	}
	else if (a.GetX()+10>b.Getright()) {//Nếu vị trí của bóng nằm ngoài giới hạn phải của ván tự động
		b.Move(x);//Di chuyển sang phải
	}
}

//Mode Chơi nâng cao
void GameManager::RunLevelUp()
{
	char s;//biến giữ giá trị tư bàn phím
	//initwindow(WIDTH + 200, HEIGHT);
	a.Draw();//hiện bóng
	b.Draw();//hiện ván trên
	c.Draw();//hiện ván dưới
	while (!win)//chưa có người thắng
	{
		int x = 10;//Bước nhảy của ván tự động
		int t1 = a.GetScore1();//Lấy điểm của người chơi 1
		int t2 = a.GetScore2();//Lấy điểm của người chơi 2
		char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
		char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(6);//Set màu thành vàng
		circle(WIDTH / 2, HEIGHT / 2, 30);//Vẽ vòng tròn giữa sân
		line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);//vẽ biên ngang chia sân 
		line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
		line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
		b.Delete();//Xoá ván tự dộng ở vị trí cũ
		TuChoi(x);//Cập nhật vị trí mới của ván tự động
		b.Draw();//Vẽ ván tự động
		if (kbhit())//Có dữ liệu từ bàn phím
		{
			s = getch();//Nhận phím
			c.Delete();//Xoá ván người chơi ở vị trí cũ
			InputPvC(s);//Cập nhật vị trí mới cho ván
			c.Draw();//Vẽ lại ván người chơi
		}
		a.checkPaddle(b);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		a.checkPaddle(c);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		LevelUp();//Nếu tốc độ bóng = 8 hiện ván giữa sân ra
		delay(25);//Dừng chương trình trong 25ms
		a.Delete();//Xoá bóng ở vị trí hiện tại
		a.Update();//Cập nhật vị trí mới cho bóng
		a.Edges();//Kiểm tra bóng có chạm biên không
		if (t1 != a.GetScore1() || t2 != a.GetScore2())//Nếu điểm hiện tại thay đổi so với ban đầu
		{
			e.Delete();//Xoá ván giữa sân
		}
		setcolor(6);//Set màu thành vàng
		itoa(a.GetScore1(), score1, 10);//Chuyển điểm người chơi 1 từ kiểu int sang dạng chuỗi
		itoa(a.GetScore2(), score2, 10);//Chuyển điểm người chơi 2 từ kiểu int sang dạng chuỗi
		settextstyle(0, 0, 30);//Set kiểu chữ
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);////Hiện điểm người chơi 1 ra màn hình
		settextstyle(0, 0, 30);//Set kiểu chữ
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
		isWin();//Kiểm tra xem có người chơi nào chiến thắng chưa
		a.Draw();//Vẽ lại bóng
	}
}

//Mode chơi với máy
void GameManager::RunPvC()
{

	char s;
	//initwindow(WIDTH + 200, HEIGHT);
	a.Draw();//hiện bóng
	b.Draw();//hiện ván trên
	c.Draw();//hiện ván dưới
	while (!win)//chưa có người thắng
	{
		int x = 10;//Bước nhảy của ván tự động
		char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
		char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(6);//Set màu thành vàng
		circle(WIDTH / 2, HEIGHT / 2, 30);//Vẽ vòng tròn giữa sân
		line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);//vẽ biên ngang chia sân 
		line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
		line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
		b.Delete();//Xoá ván tự dộng ở vị trí cũ
		TuChoi(x);//Cập nhật vị trí mới của ván tự động
		b.Draw();//Vẽ ván tự động
		if (kbhit())//Có dữ liệu từ bàn phím
		{
			s = getch();//Nhận phím
			c.Delete();//Xoá ván người chơi ở vị trí cũ
			InputPvC(s);//Cập nhật vị trí mới cho ván
			c.Draw();//Vẽ lại ván người chơi
		}
		a.checkPaddle(b);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		a.checkPaddle(c);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		delay(25);//Dừng chương trình trong 25ms
		a.Delete();//Xoá bóng ở vị trí hiện tại
		a.Update();//Cập nhật vị trí mới cho bóng
		a.Edges();//Kiểm tra bóng có chạm biên không
		setcolor(6);//Set màu thành vàng
		itoa(a.GetScore1(), score1, 10);//Chuyển điểm người chơi 1 từ kiểu int sang dạng chuỗi
		itoa(a.GetScore2(), score2, 10);//Chuyển điểm người chơi 2 từ kiểu int sang dạng chuỗi
		settextstyle(0, 0, 30);//Set kiểu chữ
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);////Hiện điểm người chơi 1 ra màn hình
		settextstyle(0, 0, 30);//Set kiểu chữ
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
		isWin();//Kiểm tra xem có người chơi nào chiến thắng chưa
		a.Draw();//Vẽ lại bóng
	}
}

void GameManager::RunPvP()
{
	char s;
	//initwindow(WIDTH + 200, HEIGHT);
	a.Draw();//hiện bóng
	b.Draw();//hiện ván trên
	c.Draw();//hiện ván dưới
	while (!win)//chưa có người thắng
	{
		//int x = 10;
				char score1[50];//chuỗi nhận điểm người chơi 1 để in ra màn hình
		char score2[50];//chuối nhận điẻm người chơi 2 để in ra màn hình
		setcolor(6);//Set màu thành vàng
		circle(WIDTH / 2, HEIGHT / 2, 30);//Vẽ vòng tròn giữa sân
		line(5, 5, WIDTH, 5);//Vẽ biên ngang trên
		line(5, HEIGHT - 15, WIDTH, HEIGHT - 15);//vẽ biên ngang dưới
		line(5, HEIGHT / 2, WIDTH, HEIGHT / 2);//vẽ biên ngang chia sân 
		line(WIDTH, 5, WIDTH, HEIGHT - 15);//Vẽ biên dọc bên phải
		line(5, 5, 5, HEIGHT - 15);//Vẽ biên dọc bên trái
		if (kbhit())//Có dữ liệu từ bàn phím
		{
			s = getch();//Nhận phím
			b.Delete();//Xoá ván người chơi 1 ở vị trí cũ
			c.Delete();//Xoá ván người chơi 2 ở vị trí cũ
			InputPvP(s);//Cập nhật vị trí mới cho ván
			b.Draw();//Vẽ ván người chơi 1
			c.Draw();//Vẽ ván người chơi 1
		}
		a.checkPaddle(b);//Kiểm tra bóng có chạm ván tự động không để đổi hướng và tăng tốc
		a.checkPaddle(c);//Kiểm tra bóng có chạm ván của người chơi không để đổi hướng và tăng tốc
		delay(25);//Dừng chương trình trong 25ms
		a.Delete();//Xoá bóng ở vị trí hiện tại
		a.Update();//Cập nhật vị trí mới cho bóng
		a.Edges();//Kiểm tra bóng có chạm biên không
		setcolor(6);//Set màu thành vàng
		itoa(a.GetScore1(), score1, 10);//Chuyển điểm người chơi 1 từ kiểu int sang dạng chuỗi
		itoa(a.GetScore2(), score2, 10);//Chuyển điểm người chơi 2 từ kiểu int sang dạng chuỗi
		settextstyle(0, 0, 30);//Set kiểu chữ
		outtextxy(WIDTH + 100, HEIGHT / 4, score1);////Hiện điểm người chơi 1 ra màn hình
		settextstyle(0, 0, 30);//Set kiểu chữ
		outtextxy(WIDTH + 100, 3 * HEIGHT / 4, score2);//Hiện điểm người chơi 2 ra màn hình
		isWin();//Kiểm tra xem có người chơi nào chiến thắng chưa
		a.Draw();//Vẽ lại bóng
	}
}

//Phương thức vẽ nút lựa chọn trong Menu
void GameManager::drawButton(int left,int  top, int right, int bottom, int test, char s[]) {
	if (test == 1) {//con trỏ chuột đang ở trên nút 
		setcolor(4);//Set màu đỏ
		rectangle(left, top, right, bottom);//Vẽ hình chữ nhật theo toạ độ truyền vào
		setcolor(14);//Set màu chữ thành vàng
		settextstyle(0, 0, 13);//Set kiểu chữ
		moveto(left + 150, top + 15);//Di chuyển con trỏ đến giữa nút
		settextjustify(1, 2);//Set kiểu viết chữ từ con trỏ sang 2 bên
		outtextxy(left + 150, top + 15, s);//hiện chuỗi s lên nút
	}
	else {
		setcolor(14);//Set màu vàng
		rectangle(left, top, right, bottom);//Vẽ hình chữ nhật theo toạ độ truyền vào
		setcolor(4);//Set màu chữ thành đỏ
		settextstyle(0, 0, 13);//Set kiểu chữ
		moveto(left + 150, top + 15);//Di chuyển con trỏ đến giữa nút
		settextjustify(1, 2);//Set kiểu viết chữ từ con trỏ sang 2 bên
		outtextxy(left + 150, top + 15, s);//hiện chuỗi s lên nút
	}
}

//Phương thức hiện Menu để vào game
void GameManager::Menu() 
{
	int left = 1000/ 2 - 150;//giới hạn bên trái nút
	int right =  1000 / 2 + 150;//giới hạn bên phải nút
	int top = 100;//giới hạn bên trên nút đầu tiên
	int bottom = 150;//giới hạn bên dưới nút đầu tiên
	int x, y;//vị trí con trỏ chuột
	int quit = 0;//biến kiểm tra để dừng trò chương trình
	initwindow(WIDTH + 200, HEIGHT);//Hiện cửa số BGI
	drawButton(left, top, right, bottom, 0, "Player vs Player");//Vẽ nút đầu tiên
	drawButton(left, top + 100, right, bottom + 100, 0,"Player vs Computer");//Vẽ nút 2
	drawButton(left, top + 200, right, bottom + 200, 0,"Play Hard");//Vẽ nút 3
	drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");//Vẽ nút 4
	while (!quit) {//nếu quit vẫn = 0
		if (ismouseclick(WM_MOUSEMOVE)) {//Có sự kiện di chuyển chuột
			getmouseclick(WM_MOUSEMOVE, x, y);//lấy vị trí con trỏ chuột nơi diễn ra sự kiện
			if (x >= left && x <= right && y >= top && y <= bottom) {//vị trí nằm trong nút 1 thì vẽ lại nút 1 với màu khác
				drawButton(left, top, right, bottom, 1, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 0, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 100 && y <= bottom + 100) {//vị trí nằm trong nút 2 thì vẽ lại nút 2 với màu khác
				drawButton(left, top, right, bottom, 0, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 1, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 0, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 200 && y <= bottom + 200) {//vị trí nằm trong nút 3 thì vẽ lại nút 3 với màu khác
				drawButton(left, top, right, bottom, 0, "Player vs Player");
				drawButton(left, top + 100, right, bottom + 100, 0, "Player vs Computer");
				drawButton(left, top + 200, right, bottom + 200, 1, "Play Hard");
				drawButton(left, top + 300, right, bottom + 300, 0, "Quit Game");
			}
			else if (x >= left && x <= right && y >= top + 300 && y <= bottom + 300)//vị trí nằm trong nút 4 thì vẽ lại nút 4 với màu khác
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
		if (ismouseclick(WM_LBUTTONDOWN)) {//Nếu có nháy chuột trái
			getmouseclick(WM_LBUTTONDOWN, x, y);//lấy vị trí con trỏ tại nơi nháy chuột
			if (x >= left && x <= right && y >= top && y <= bottom) {//Vị trí thuộc nút 1
				cleardevice();//Xoá những gì đang có trên màn hình 
				Reset();//Khởi tạo lại tất cả đối tượng
				RunPvP();//Vào mode chơi với người
			}
			else if (x >= left && x <= right && y >= top + 100 && y <= bottom + 100) {//Vị trí thuộc nút 2
				cleardevice();//Xoá những gì đang có trên màn hình 
				Reset();//Khởi tạo lại tất cả đối tượng
				RunPvC();//Vào mode chơi với máy
			}
			else if (x >= left && x <= right && y >= top + 200 && y <= bottom + 200) {//Vị trí thuộc nút 3
				cleardevice();//Xoá những gì đang có trên màn hình 
				Reset();//Khởi tạo lại tất cả đối tượng
				RunLevelUp();//Vào mode chơi với máy
			}
			else if (x >= left && x <= right && y >= top + 300 && y <= bottom + 300) {//Vị trí thuộc nút 4
				exit(0);
				//Thoat khỏi chương trình
			}
			cleardevice();//Xoá những gì đang có trên màn hình
		}
	}
}

//Phuong thức Reset các đối tượng trong game về ban đầu
void GameManager::Reset()
{
	win = 0;//khỏi tạo biến win về 0
	a.SetScore();//Reset lại điểm
	b.Reset();//Reset lại ván trên
	c.Reset();//Reset lại ván dưới
}

//Phương thức hiện ván thứ 3 ơr giữa sân
void GameManager::LevelUp()
{
	if (abs(a.GetSpeedY()) > 8)//Nếu tốc độ bóng lơn hơn 8
	{
		e.Draw();//Hiện ván
		a.checkPaddle(e);//Kiểm tra bóng có chạm vào ván không
	}
}