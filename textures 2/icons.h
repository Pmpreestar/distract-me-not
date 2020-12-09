#ifndef ICONS_H
#define ICONS_H
#include "TexRect.h"
//NOTE TO SELF CAPITALIZE THE i in ICONS


/*
sprite that represents each icon, their x and y, width and height
public constructor 
draw functin
virutal void move function
*/

class Icons: public TexRect{
    float x;
    float y;
    float w;
    float h;

public:
	Icons(float, float, float, float);

	void draw(float z=0);
	void setY(float y);
	float getY() const;
	float getX() const;
	void setX(float x);
	bool contains(float, float) const;
};

#endif
