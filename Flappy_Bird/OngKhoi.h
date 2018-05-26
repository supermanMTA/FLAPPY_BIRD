#pragma once

#include "dinhnghia.h"
#include "Picture.h"

class OngKhoi
{
private:
	/// huong cua ong khoi
	/// 1 la huong xuong duoi, 2 la huong len tren
	int Rotation;
	/// do cao cua than ong khoi
	int high;
	/// toa do theo chieu ngang cua ong khoi
	int x;
private:
	/// luu de khong phai load anh nhieu
	Picture Than, Dau;
public:
	OngKhoi();
	~OngKhoi();
	void setOngKhoi(int x, int high, int rotation);
	void display(RenderWindow &app);
	void move();
	int getX();
	/// cac ham ho tro load anh nhanh
	bool vacham(int x, int y, int sizex, int sizey);
private:
	/// kiem tra 2 hinh chu nhat co cat nhau k
	bool catnhau(int, int, int, int, int, int, int, int);
	/// kiem tra 2 doan thang cat nhau
	bool catnhaudoanthang(int, int, int, int);
};

