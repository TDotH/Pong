#ifndef UTIL_H
#define UTIL_H

#include <SDL.h>

//Window constraints
static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

//Initalizes SDL subsystems
void initSDL();

//Closes SDL subsystems
void closeSDL();

//Checks for collision between two objects
bool checkCollision( SDL_Rect& a, SDL_Rect& b );

#endif
