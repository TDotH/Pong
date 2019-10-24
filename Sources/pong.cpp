#include <iostream>
#include <SDL.h>

#include "util.h"
#include "ball.h"
#include "paddle.h"

extern SDL_Renderer* gRenderer;

int main(int argc, char* argv[] ) {

    initSDL();

    SDL_Event eventHandler;

    //Player1, player 2
    int[] score = {0, 0};

    Ball aBall;
    Player aPlayer;
    Ai_Player aiPlayer;

    aBall.resetPos( WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 1, 1 );
    aPlayer.resetPos( 50, WINDOW_HEIGHT/2, 0, 0 );
    aiPlayer.resetPos( WINDOW_WIDTH - 50 , WINDOW_HEIGHT/2, 0, 0 );

    //Main game loop
    bool quit = false;
    while( !quit ) {

       while( SDL_PollEvent( &eventHandler ) != 0 ) {

            if ( eventHandler.type == SDL_QUIT ) {

                    quit = true;
            }
            else {

                aPlayer.eventHandler( eventHandler );
            }
       }

       //Do ai stuff
       aiPlayer.aiHandler( aBall.getPosY() );

       //Move objects
       aBall.move( aPlayer.getCollider(), aiPlayer.getCollider() );
       aPlayer.move();
       aiPlayer.move();

       //Clear screen
       SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
       SDL_RenderClear( gRenderer );

       //Render new positions
       aBall.render();
       aPlayer.render();
       aiPlayer.render();

       //Render Everything
       SDL_RenderPresent( gRenderer );
    }

    closeSDL();

    return 0;
}
