#ifndef UTIL_H
#define UTIL_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

//Window constraints
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

//Initalizes SDL subsystems
void initSDL();

//Closes SDL subsystems
void closeSDL();

//Checks for collision between two objects
//bool checkCollision( SDL_Rect& a, SDL_Rect& b );

//Loads an image
SDL_Surface * loadImage( const char* imageLoc );

#endif
