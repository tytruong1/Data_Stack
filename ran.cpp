#include <iostream>
#include "kmin_console.h"
#include <ctime>
using namespace std;
#define TRAI 1
#define PHAI 2
#define LEN 3
#define XUONG 4
#define Max 100

int xCu = 0, yCu = 0;
int huong = PHAI;
int diem = 0, step = 100;
int xMin = 15, yMin = 6, yMax = 25, xMax = 50;
int xTuong = xMin, yTuong = yMin;
int x = xMin + 1, y = yMin + 1, xMoi = xMin + 6, yMoi = yMin + 5;
int dot = 3;
int ranX[Max], ranY[Max];


//Bắt sự kiện bàn phím
void xuLyDiem(int x, int y);
void khoiChayRan();
void batSuKien();
void tuong();
void xuLyMoi();
void xuLyDot();
void in_ASCII()
{
	for (int i = 0; i <= 255; i++)
		cout << i << ": " << (char)i << endl;
}
void upDateViTri();
void veRan();
bool xuLyVaCham();
bool chamThan();


int main()
{
	noCursorType();

	ranX[0] = 18;
	ranX[1] = 17;
	ranX[2] = 16;
	ranY[0] = ranY[1] = ranY[2] = 7;
	khoiChayRan();
	gotoXY(0, yMax + 2);

	//in_ASCII();
	system("pause");
	return 0;
}
void xuLyDiem(int x, int y)
{

	gotoXY(xMin, yMin - 2);
	cout << "Score: " << diem;

	if (ranX[0] == xMoi && ranY[0] == yMoi)//khi vừa đi tới điểm mồi thì lập tức cập nhật điểm
	{
		dot++;
		diem++;
		gotoXY(xMin, yMin - 2);
		cout << "Score: " << diem;
		xuLyMoi();
	}
}
void xuLyDot()
{

	
}

void khoiChayRan()
{
	//setTextColor(4);
	tuong();
	//setTextColor(15);
	gotoXY(20, 1);
	cout << "Developer: TVT";
	gotoXY(xMoi, yMoi);
	setTextColor(4);
	cout << (char)3;
	setTextColor(15);
	while (true)
	{
		//khi đụng vào biên tường sẽ kết thúc game
		
		upDateViTri();
		veRan();
		xuLyDiem(ranX[0], ranY[0]);
		if (xuLyVaCham())
			break;
		Sleep(step);
		batSuKien();
		
	}
}
void upDateViTri()
{
	xCu = ranX[dot - 1];
	yCu = ranY[dot - 1];
	
	for (int i = dot - 1; i > 0;i--)
	{
		ranX[i] = ranX[i - 1];
		ranY[i] = ranY[i - 1];
	}
	
	if (huong == PHAI)
	{
		ranX[0]++;
	}
	else if (huong == XUONG)
	{
		ranY[0]++;
	}
	else if (huong == TRAI)
	{
		ranX[0]--;
	}
	else if (huong == LEN)
	{
		ranY[0]--;
	}
}
void veRan()
{
	gotoXY(xCu, yCu);//xóa vị trí cũ
	cout << " ";
	for (int i = 0; i < dot; i++)
	{
		if (i == 0)
		{
			gotoXY(ranX[i], ranY[i]);// in vị trí mới
			setTextColor(1);
			cout << (char)2;
			setTextColor(15);
		}
		else
		{ 
			gotoXY(ranX[i], ranY[i]);
			cout << (char)249;
		}
	}
}
void batSuKien()
{
	if (huong == PHAI)
	{
	
		int key = inputKey();
		if (key == 's')
			huong = XUONG;
		else if (key == 'w')
			huong = LEN;
	}
	else if (huong == TRAI)
	{
		
		int key = inputKey();
		if (key == 's')
			huong = XUONG;
		else if (key == 'w')
			huong = LEN;
	}
	else if (huong == LEN)
	{
		
		int key = inputKey();
		if (key == 'a')
			huong = TRAI;
		else if (key == 'd')
			huong = PHAI;
	}
	else
	{
		
		int key = inputKey();
		if (key == 'a')
			huong = TRAI;
		else if (key == 'd')
			huong = PHAI;
	}
}
bool xuLyVaCham()
{
	if (((ranX[0] == xMin - 1 || ranX[0] == xMax - 1) &&
		(ranY[0] >= yMin - 1 && ranY[0] <= yMax)) || ((ranY[0] == yMin || ranY[0] == yMax - 1)
		&& (ranX[0] >= xMin  && ranX[0] <= xMax)) || chamThan())
	{
		system("cls");
		gotoXY(25, 10);
		cout << "Game Over.";
		return true;
	}
	return false;
}
bool chamThan()
{
	for (int i = 1; i < dot; i++)
	{
		if (ranX[0] == ranX[i] && ranY[0] == ranY[i])
			return true;
	}
	return false;
}
void tuong()
{

	bool flag_right = true, flag_down = false, flag_left = false, flag_up = false;

	while (true)
	{
		if (flag_right)
		{

			gotoXY(xTuong, yTuong);
			cout << "*";
			xTuong++;
			if (xTuong >= xMax - 1)
			{
				flag_right = false;
				flag_down = true;
				flag_left = false;
				flag_up = false;
			}
		}
		if (flag_down)
		{

			gotoXY(xTuong, yTuong);
			cout << "*";
			yTuong++;

			if (yTuong >= yMax - 1)
			{
				flag_right = false;
				flag_down = false;
				flag_left = true;
				flag_up = false;
			}
		}
		if (flag_left)
		{

			gotoXY(xTuong, yTuong);
			cout << "*";
			xTuong--;

			if (xTuong <= xMin - 1)
			{
				flag_right = false;
				flag_down = false;
				flag_left = false;
				flag_up = true;
			}
		}
		if (flag_up)
		{

			gotoXY(xTuong, yTuong);
			cout << "*";
			yTuong--;

			if (yTuong <= yMin - 1)
			{
				break;
			}
		}
	}
}
void xuLyMoi()
{
	srand(time(NULL));//xMin = 15, yMin = 6, yMax = 15, xMax = 35;
	yMoi = (yMin + 1) + rand() % (yMax - yMin - 2);// yMin-2    - >    yMax-1
	if (yMoi == y)//tránh trường hợp rand ngay sau nốt rắn
	{
		yMoi = (yMin + 1) + rand() % (yMax - yMin - 2);
	}
	xMoi = (xMin + 1) + rand() % (xMax - xMin - 2);
	gotoXY(xMoi, yMoi);
	setTextColor(4);
	cout << (char)3;
	setTextColor(15);
}

