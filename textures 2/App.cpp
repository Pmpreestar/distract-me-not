#include <iostream>
#include "App.h"

static App* singleton;
int level = 0; //variable that stores what level game is currently on 0 = main menu, 1 = new game, 2 = facts, 3 = game state  

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    shapes.push_front(new TexRect("Main Menu2.png", -1, 1, 2, 2));
    shapes.push_back(new Rect(-0.55, 0.35, 1.1, 0.25, 0,0,0, 0.15)); //new game button
    shapes.push_back(new Rect(-0.55, 0.02, 1.1, 0.25, 0,0,0, 0.15)); //exit button
    shapes.push_back(new Rect(-0.55, -0.32, 1.1, 0.25, 0,0,0, 0.15)); //facts button
} 

void App::draw() {
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        (*i)->draw();
    }
    singleton->redraw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }    
 }
void App::leftMouseDown(float x, float y){
    if(level == 0){
        Rect* newGameButton = (Rect*)shapes[1];
        if (newGameButton->contains(x, y)){ //if click on new game button, show the directions 
            shapes.clear();
            shapes.push_front(new TexRect("Directions2.png", -1, 1, 2, 2)); 
            shapes.push_back(new Rect(-0.26, -0.55, 1.05, 0.25, 0,0,0, 0.15)); // start button on the directions screen 
            std::cout << shapes.size() << std::endl;
            level = 1;
        } 
        Rect* exitButton = (Rect*)shapes[2];
        if(exitButton->contains(x, y)){ //if click on exit button, exit the game
            exit(0); 
        }
        Rect* factsButton = (Rect*)shapes[3];
        if (factsButton->contains(x,y)){
            shapes.clear();
            shapes.push_front(new TexRect("Facts2.png", -1, 1, 2, 2));
            std::cout << shapes.size() << std::endl;
            level = 2;
        }   
    }
    if (level == 1){
        Rect* newGameButton = (Rect*)shapes[1];
        if (newGameButton->contains(x, y)){ //if click on new game button, show the directions 
            shapes.clear();
            std::cout << shapes.size() << std::endl;
            shapes.push_front(new TexRect("Game.png", -1, 1, 2, 2)); 
            level = 3;
        } 
    }
    else if (level == 2){
    }
}
App::~App(){   
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
