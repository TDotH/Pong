#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL.h>
#include "util.h"

extern SDL_Renderer * gRenderer;

class LTexture {

  public:
    LTexture();
    ~LTexture();

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render( int x, int y );

    //Creates texture from simple RGB Surface
    void createTexture( int aWidth, int aHeight, const char* objName );

    //Getters
    int getWidth()  { return mWidth; };
    int getHeight() { return mHeight; };

  private:
    //The actual texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;

};

#endif
