#include "Picture.h"


Picture::Picture(){
	this->Rotation = 0;
	this->color = Color::White;
	this->x1 = 0;
	this->y1 = 0;
}

Picture::Picture(string path, int x, int y, int sizex, int sizey){
	this->texture.loadFromFile(path);
	this->x = x;
	this->y = y;
	this->sizex = sizex;
	this->sizey = sizey;
	this->Rotation = 0;
	setColor(Color::White);
	this->x1 = 0;
	this->y1 = 0;
}
Picture::Picture(string path, int x, int y, int sizex, int sizey, Color color){
	this->texture.loadFromFile(path);
	this->x = x;
	this->y = y;
	this->sizex = sizex;
	this->sizey = sizey;
	this->Rotation = 0;
	setColor(color);
	this->x1 = 0;
	this->y1 = 0;
}

Picture::~Picture(){
}

void Picture::setColor(Color red){
	this->color = red;
}

void Picture::setRotation(int rotation){
	this->Rotation = rotation;
}

void Picture::display(RenderWindow &app){
	Sprite sprite(this->texture);
	sprite.setColor(this->color);
	sprite.setOrigin(this->x1, this->y1);
	sprite.setRotation(this->Rotation);
	sprite.setScale(double(this->sizex) / this->texture.getSize().x, double(this->sizey) / this->texture.getSize().y);
	sprite.setPosition(this->x, this->y);
	app.draw(sprite);  //ve len app
}

void Picture::setPicture(string path, int x, int y, int sizex, int sizey){
	this->texture.loadFromFile(path);
	this->x = x;
	this->y = y;
	this->sizex = sizex;
	this->sizey = sizey;
	this->Rotation = 0;
	setColor(Color::White);
	this->x1 = 0;
	this->y1 = 0;
}

void Picture::setPicture(string path, int x, int y, int sizex, int sizey, Color color){
	this->texture.loadFromFile(path);
	this->x = x;
	this->y = y;
	this->sizex = sizex;
	this->sizey = sizey;
	this->Rotation = 0;
	setColor(color);
	this->x1 = 0;
	this->y1 = 0;
}

void Picture::setSize(int sizex, int sizey){
	this->sizex = sizex;
	this->sizey = sizey;
}

void Picture::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}

void Picture::setOrigin(int x,int y){
	this->x1 = x;
	this->y1 = y;
}