#include "Bird.h"
Bird::Bird(){
	this->x = 0;
	this->y = 0;
	this->Rotation = 0;
	this->dongho.restart();
	this->chim.setPicture("image/bird.png", 0, 0, sizex, sizey);
	this->chim.setOrigin(17, 12);
}
Bird::Bird(int x, int y){
	this->x = x;
	this->y = y;
	this->Rotation = 0;
	this->dongho.restart();
	this->chim.setPicture("image/bird.png", 0, 0, sizex, sizey);
	this->chim.setOrigin(17, 12);
}

Bird::~Bird(){
}

void Bird::setRotation(int x){
	this->Rotation = x;
	if (x == 1) this->dongho.restart();// con chim lay trang thai
}

void Bird::move(){
	/// neu con chim bay len chi cho no bay len 30 ms roi doi huong
	Time thoigian = dongho.getElapsedTime();
	if (thoigian.asMilliseconds() >= 30 && this->Rotation == 1) this->Rotation = 0;
	/// bay len thi nhanh hon roi xuong
	if (this->Rotation == 0) this->y += 3;// roi xuong
	else this->y -= 5;// bay len rotation =1;

	/// ra ngoai man hinh thi chan lai
	if (this->y < 0) this->y = 0;
	if (this->y > 400) this->y = 400;
}

void Bird::display(RenderWindow &app){
	this->chim.setPosition(this->x, this->y);
	/// xem huong cua con chim de in ra huong
	if (this->Rotation == 0) this->chim.setRotation(15);// lay goc quay cua con chim trong may
	if (this->Rotation == 1)this->chim.setRotation(-15);
	/// neu rotation==-1 tuc la chim chua bay
	if (this->Rotation == -1) this->chim.setRotation(0);
	this->chim.display(app);
}

Vector2i Bird::getPosition(){
	Vector2i ans;
	ans.x = x;
	ans.y = y;
	return ans;
}

Vector2i Bird::getSize(){
	Vector2i ans;
	ans.x = sizex;
	ans.y = sizey;
	return ans;
}