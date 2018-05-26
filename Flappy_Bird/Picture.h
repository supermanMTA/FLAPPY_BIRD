#pragma once
#include "dinhnghia.h"

class Picture
{
private:
	Texture texture;  // la mot anh
	string path;   //ten duong dan vao anh
	int x, y;  //toa do
	int sizex, sizey;  //kich thuoc anh muon in ra
	int Rotation;  //goc quay
	Color color;
	/// tam quay
	int x1, y1;   
public:
	Picture();
	Picture(string path, int x, int y, int sizex, int sizey);
	Picture(string path, int x, int y, int sizex, int sizey, Color color);
	~Picture();
	void setPicture(string path, int x, int y, int sizex, int sizey);
	void setPicture(string path, int x, int y, int sizex, int sizey, Color color);
	void setColor(Color color);
	void setRotation(int rotation);
	void setSize(int sizex, int sizey);
	void setPosition(int x, int y);
	void display(RenderWindow &app);
	void setOrigin(int x, int y);
};

