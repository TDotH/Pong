#ifndef PADDLE_H
#define PADDLE_H

class Paddle {

    public:

        Paddle();
        ~Paddle();

        //The dimensions of the paddle
        static const int PADDLE_WIDTH = 20;
        static const int PADDLE_HEIGHT = 60;

        //Moves paddle
        void move();

        //Renders paddle
        void render();

        //Returns collision box
        SDL_Rect getCollider() { return mCollider );

    private:

        //X and Y offsets
        int mPosX, mPosY;

        //Y Velocity of the paddle
        int mVelY;

        //The paddle texture
        LTexture paddleTexture;

        //Paddle's collision box
        SDL_Rect mCollider;

};

#endif
