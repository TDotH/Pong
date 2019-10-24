#include "ball.h"

Ball::Ball() {

    //Create ball texture
    ballTexture.createTexture( BALL_WIDTH, BALL_HEIGHT, image );

    //Create collision box
    mCollider.w = BALL_WIDTH;
    mCollider.h = BALL_HEIGHT;

    goal = false;
}

Ball::~Ball() {

    ballTexture.free();
}

void Ball::move( SDL_Rect a, SDL_Rect b) {

    //Move the ball left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    //Move the ball up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    //Check for collisions against paddles
    if( SDL_HasIntersection( &mCollider, &a ) || ( SDL_HasIntersection( &mCollider, &b ) ) ) {

        //Move back( or forward )
        mPosX -= mVelX;

        //Increase and flip ball's velocity
        mVelX += ( mVelX > 0 ) ? .01 : -.01;
        mVelY += ( mVelY > 0 ) ? .01 : -.01;
        mVelX = -mVelX;
    }

    //Upper and lower bound collisions
    if( ( mPosY < 0 ) || ( ( mPosY + BALL_HEIGHT ) > WINDOW_HEIGHT ) ) {

            //Move up( or down )
            mPosY -= mVelY;

            //Flip ball's velocity
            mVelY = -mVelY;
    }

    //Left and right bound collisions
    if( ( mPosX < 0 ) || ( ( mPosX + BALL_WIDTH ) > WINDOW_WIDTH ) ) {

        //Set goal flag
        goal = true;

        //Move back( or forward )
        mPosX -= mVelX;

        //Increase and flip ball's velocity
        mVelX += ( mVelX > 0 ) ? 1 : -1;
        mVelY += ( mVelY > 0 ) ? 1 : -1;
        mVelX = -mVelX;
    }

    return;
}

void Ball::render() {

    ballTexture.render( mPosX, mPosY );
}

void Ball::resetPos( int posX, int posY, int velX, int velY ) {

    mPosX = posX;
    mPosY = posY;

    mVelX = velX;
    mVelY = velY;

    mCollider.x = mPosX;
    mCollider.y = mPosY;

    //Reset goal flag
    goal = false;

    render();

    return;
}


