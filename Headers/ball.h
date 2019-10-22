#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "LTexture.h"
#include "util.h"

extern static int WINDOW_WIDTH;
extern static int WINDOW_HEIGHT;

class Ball {

  public:

      Ball();
      ~Ball();

      //The dimensions of the ball
      static const int BALL_WIDTH = 20;
      static const int BALL_HEIGHT = 20;

      //Moves the dot and checks for collisions
      void move();

      //Shows dot on the screen
      void render();

      //Resets ball position and velocity
      void resetPos( int posX, int posY, int velX, int velY );

  private:
      //The X and Y offsets of the ball
      int mPosX, mPosY;

      //The velocity of the dot
      int mVelX, mVelY

      //Ball's texture
      LTexture ballTexture;

      //Ball's collision box
      SDL_Rect mCollider;

};


#endif

