#include "paddle.h"

Paddle::Paddle() {

    //Create texture
    paddleTexture.createTexture( PADDLE_WIDTH, PADDLE_HEIGHT, image );

    //Set collision box
    mCollider.w = PADDLE_WIDTH;
    mCollider.h = PADDLE_HEIGHT;
}

Paddle::~Paddle() {

    paddleTexture.free();
}

void Paddle::move() {

    //First, move paddle
    mPosX += mVelX;
    mPosY += mVelY;

    //Move collision box
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    //Check if paddle is too far up or down
    if( (  mPosY < 0 ) || ( ( mPosY + PADDLE_HEIGHT ) > WINDOW_HEIGHT) ) {

           mPosY -= mVelY;
    }

    return;
}

void Paddle::render() {

    paddleTexture.render( mPosX, mPosY );
    return;
}

void Paddle::resetPos( int posX, int posY, int velX, int velY ) {

    //Set position
    mPosX = posX;
    mPosY = posY;

    //Set velocity
    mVelX = velX;
    mVelY = velY;

    //Set collider position
    mCollider.x = mPosX;
    mCollider.y = mPosY;

    //Rerender
    render();
    return;
}

void Player::eventHandler( SDL_Event& anEvent ) {

    //If a key was pressed
    if( ( anEvent.type == SDL_KEYDOWN ) && ( anEvent.key.repeat == 0 ) ) {

        //Adjust the velocity
        switch( anEvent.key.keysym.sym ) {

            case SDLK_w: mVelY -= PADDLE_VELOCITY; break;
            case SDLK_s: mVelY += PADDLE_VELOCITY; break;
        }
    }

    //If a key was released
    if( ( anEvent.type == SDL_KEYUP ) && ( anEvent.key.repeat == 0 ) ) {

        //Adjust the velocity
        switch( anEvent.key.keysym.sym ) {

            case SDLK_w: mVelY += PADDLE_VELOCITY; break;
            case SDLK_s: mVelY -= PADDLE_VELOCITY; break;
        }
    }

    return;
}

void Ai_Player::aiHandler( int ballY ) {

    //If ball is above paddle position
    if( ballY > ( mPosY + PADDLE_HEIGHT/2 ) ) {

        mVelY = PADDLE_VELOCITY;
    }

    //If ball is below paddle position
    else if( ballY < ( mPosY - PADDLE_HEIGHT/2 ) ) {

        mVelY = -PADDLE_VELOCITY;
    }

    //Neither
    else {

         mVelY = 0;
    }

    return;
}
