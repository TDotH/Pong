#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "LTexture.h"

extern std::random_device rd;
extern std::mt19937  mt;
extern std::uniform_int_distribution<int> startDist;

class Ball {

  public:

      Ball();
      ~Ball();

      //The dimensions of the ball
      static const int BALL_WIDTH = 10;
      static const int BALL_HEIGHT = 10;

      //Moves the dot and checks for collisions
      void move( SDL_Rect a, SDL_Rect b);

      //Shows dot on the screen
      void render();

      //Resets ball position and velocity
      void resetPos( int posX, int posY, int velX, int velY );

      int getPosY() { return mPosY; };
      int getPosX() { return mPosX; };

      bool getGoalFlag() { return goal; };

  private:
      //The X and Y offsets of the ball
      int mPosX, mPosY;

      //The velocity of the dot
      int mVelX, mVelY;

      //Image location of ball
      const char* image = "ball.png";

      //Ball's texture
      LTexture ballTexture;

      //Ball's collision box
      SDL_Rect mCollider;

      //Score flag
      bool goal;
};


#endif

