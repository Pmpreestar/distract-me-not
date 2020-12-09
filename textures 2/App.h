#ifndef App_h
#define App_h

#include <vector>
#include <deque>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "icons.h"


class App: public GlutApp {

std::deque<Shape*> shapes;

public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    
    void leftMouseDown(float x, float y);

    ~App();
};

#endif
