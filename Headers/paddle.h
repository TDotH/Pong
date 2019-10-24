#ifndef PADDLE_H
#define PADDLE_H

#include "LTexture.h"
#include "util.h"
//Contains player and ai paddles

class Paddle {

    public:

        Paddle();
        ~Paddle();

        //The dimensions of the paddle
        static const int PADDLE_WIDTH = 10;
        static const int PADDLE_HEIGHT = 60;

        //Velocity of the paddle
        static const int PADDLE_VELOCITY = 5;

        //Moves paddle
        void move();

        //Renders paddle
        void render();

        //Returns collision box
        SDL_Rect getCollider() { return mCollider; };

        //Reset paddle position
        void resetPos( int posX, int posY, int velX, int velY );

    protected:

        //X and Y offsets
        int mPosX, mPosY;

        //X and Y velocites
        int mVelX, mVelY;

        //The paddle texture
        LTexture paddleTexture;

        //Paddle's collision box
        SDL_Rect mCollider;

        //Image location
        const char* image = "paddle.png";

};

class Player : public Paddle {

    public:

        //Takes input to move paddle
        void eventHandler( SDL_Event& anEvent );
};

class Ai_Player : public Paddle {

  public:

      //Handles ai based on ball placement
      void aiHandler( int ballY );

};

#endif
