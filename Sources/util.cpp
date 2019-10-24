#include "util.h"
#include <iostream>

//Main window and renderer
SDL_Window * gWindow;
SDL_Renderer * gRenderer;

void initSDL() {

    if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {

            printf( "Unable to intialize SDL! Error: %s\n", SDL_GetError() );
    }
    int imgFlags = IMG_INIT_PNG;
    if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {

            printf( "SDL_image could not initialize! Error: %s\n", IMG_GetError() );
    }

    gWindow = SDL_CreateWindow( "Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

    //Set render background and clear screen
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
    SDL_RenderClear( gRenderer );
    SDL_RenderPresent( gRenderer );
}


void closeSDL() {

    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );

    IMG_Quit();
    SDL_Quit();
}

/*
bool checkCollision( SDL_Rect& a, SDL_Rect& b ) {

    bool collision = false;

}*/

SDL_Surface * loadImage( const char * imageLoc ) {

    SDL_Surface * loadedImage = IMG_Load( imageLoc );
    if ( !loadedImage ) {

        printf( "Unable to load image %s! Error: %s\n", imageLoc, IMG_GetError() );
    }

    return loadedImage;
}
