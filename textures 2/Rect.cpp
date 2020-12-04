#include "Rect.h"
#include "GlutApp.h"
//changed the color and size here
Rect::Rect(){
	x = -0.55;
	y = 0;
	w = 1.1;
	h = 0.25;
	r = 0;
	g = 0;
	b = 1;
	a = 0.15;

}

Rect::Rect(float x, float y, float w, float h, float r, float g, float b, float a){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a =a;

}

void Rect::draw(float z) const {
	//glColor3f(r, g, b);
	glColor4f(r,g,b,a);

	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
}


void Rect::setY(float y){
	this-> y = y;
}

void Rect::setX(float x){
	this-> x = x;
}

float Rect::getY() const {
	return y;
}

float Rect::getX() const {
	return x;
}

bool Rect::contains(float x, float y) const{
	return x >= this->x && x <= this->x + w && y <= this->y && y >= this->y - h;
}

