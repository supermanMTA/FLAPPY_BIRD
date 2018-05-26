#pragma once

#include "dinhnghia.h"
#include "Picture.h"

class Bird
{
private:
	/// kich thuoc cua con chim la 32x24
	int sizex = 32, sizey = 24;
	/// toa do cua con chim
	int x, y;
	/// huong cua con chim
	/// rotation = 1 tuc la chim dan bay len, 0 la chim dang bay xuong
	int Rotation;
private:
	/// luu hinh anh cua con chim de khong phai load nhieu
	Picture chim;
	/// dong ho de luu thoi gian bay len cua con chim
	Clock dongho;
public:
	Bird();
	Bird(int x, int y);	
	~Bird();
	void setRotation(int);
	void move();
	void display(RenderWindow &app);
	Vector2i getPosition();//
	Vector2i getSize();
};

