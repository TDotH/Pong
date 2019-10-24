#include "LTexture.h"
#include <iostream>
LTexture::LTexture() {

    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture() {

    free();
}

void LTexture::free() {

    if( mTexture ) {

        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
    return;
}

void LTexture::render( int x, int y ) {

    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );
    return;
}

void LTexture::createTexture( int aWidth, int aHeight, const char* objName ) {

    mWidth = aWidth;
    mHeight = aHeight;

    //Temp surface
    SDL_Surface* tempSurface = loadImage( objName );
    mTexture = SDL_CreateTextureFromSurface( gRenderer, tempSurface );

    if( !mTexture ) {

         printf( "Unable to create texture from %s! Error: %s\n", objName, SDL_GetError() );
    }

    SDL_FreeSurface( tempSurface );
    //std::cout << "Text";
    return;
}

