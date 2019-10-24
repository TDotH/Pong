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
    int score[] = {0, 0};

    Ball aBall;
    Player aPlayer;
    Ai_Player aiPlayer;

    aBall.resetPos( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 5, 1, 0 );
    aPlayer.resetPos( 50, WINDOW_HEIGHT/2 - 30, 0, 0 );
    aiPlayer.resetPos( WINDOW_WIDTH - 50 , WINDOW_HEIGHT/2 - 30, 0, 0 );

    //Main game loop
    bool quit = false;
    while( !quit ) {

     //Check if either player made a goal
       if( aBall.getGoalFlag() ) {

            //Ai made a goal
            if( aBall.getPosX() < 0 ) {

                score[1]++;
                aBall.resetPos( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 5, -1, startDist( mt ) );
            } else { //Player made a goal

                score[0]++;
                aBall.resetPos( WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 5, 1, startDist( mt ) );
            }

            //Reset positions
            aPlayer.resetPos( 50, WINDOW_HEIGHT/2 - 30, 0, 0 );
            aiPlayer.resetPos( WINDOW_WIDTH - 50 , WINDOW_HEIGHT/2 - 30, 0, 0 );

           //Reset renderer
           //Clear screen
           SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
           SDL_RenderClear( gRenderer );

           //Render new positions
           aBall.render();
           aPlayer.render();
           aiPlayer.render();

           //Render Everything
           SDL_RenderPresent( gRenderer );

           SDL_FlushEvents( SDL_KEYDOWN, SDL_KEYUP );

           SDL_Delay( 2000 );
       }

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

    std::cout << "Game Over!" << std::endl;
    std::cout << "Player 1 score: " << score[0] << std::endl;
    std::cout << "Player 2 score: " << score[1] << std::endl;

    return 0;
}
