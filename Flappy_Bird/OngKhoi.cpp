#include "OngKhoi.h"
OngKhoi::OngKhoi(){
	Than.setPicture("image/ongkhoi_than.png", 0, 0, 50, 0);
	Dau.setPicture("image/ongkhoi_dau.png", 0, 0, 55, 0);
	Than.setOrigin(38, 0);
	Dau.setOrigin(41, 0);
}
OngKhoi::~OngKhoi(){
}
void OngKhoi::setOngKhoi(int x, int high, int rotation){
	this->x = x;
	this->high = high;
	this->Rotation = rotation;
}
void OngKhoi::display(RenderWindow &app){
	if (Rotation){
		/// huong xuong duoi
		Than.setPosition(x, 0);
		Than.setSize(50, high);
		Dau.setPosition(x, high);
		Dau.setSize(55, 32);
	}
	else {
		/// huong len tren
		Than.setPosition(x, 422);
		Than.setSize(50, high);
		Dau.setSize(55, 32);
		Dau.setPosition(x , 422 - high);
		Than.setRotation(180);
		Dau.setRotation(180);
	}
	
	Than.display(app);
	Dau.display(app);
}
/*void OngKhoi::move(int dem,int &sum){
	
	if ( dem != 0 && dem % 2 == 0)
	{
		sum = sum + dem / 5;
	}
	this->x = this->x - sum;
}*/
void OngKhoi::move(){
	this->x -= 3;
}
int OngKhoi::getX(){
	return this->x;
}
bool OngKhoi::catnhaudoanthang(int x, int y, int x1, int y1){
	if (x >= x1 && x <= y1) return true;
	if (y >= x1 && y <= y1) return true;
	if (x1 >= x && x1 <= y) return true;
	if (y1 >= x && y1 <= y) return true;
	return false;
}
bool OngKhoi::catnhau(int x, int y, int sizex, int sizey, int x1, int y1, int sizex1, int sizey1){
	if (!catnhaudoanthang(x, x + sizex, x1, x1 + sizex1)) return false;
	if (!catnhaudoanthang(y, y + sizey, y1, y1 + sizey1)) return false;
	return true;
}

bool OngKhoi::vacham(int x, int y, int sizex, int sizey){
	x -= sizex / 2;
	y -= sizey / 2;
	/// va cham than
	int x1 = this->x;
	int y1;
	int sizex1 = 50, sizey1 = high;
	if (this->Rotation) y1 = 0; else y1 = 422 - sizey1;
	x1 -= sizex1 / 2;
	if (catnhau(x, y, sizex, sizey, x1, y1, sizex1, sizey1)) return true;
	/// va cham dau
	sizex1 = 55;
	sizey1 = 32;
	x1 = this->x;
	if (this->Rotation) y1 = high; else y1 = 422 - high - sizey1;
	x1 -= sizex1 / 2;
	if (catnhau(x, y, sizex, sizey, x1, y1, sizex1, sizey1)) return true;
	return false;
}



