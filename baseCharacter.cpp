#include "baseCharacter.h"
#include "raymath.h"

baseCharacter :: baseCharacter(){

}

void baseCharacter :: undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle baseCharacter :: getCollisionRec(){
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void baseCharacter::tick(float dt){
    worldPosLastFrame = worldPos;
    
    runningTime += dt;
    if (runningTime >= updateTime){

        runningTime = 0.0f;
        frame++;
        if (frame > maxFrame) frame = 0;

    }

    if (Vector2Length(velocity) != 0.0){

        // Set worldPos = worldPos + velocity
        worldPos = Vector2Add(worldPos,Vector2Scale(Vector2Normalize(velocity),speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;

    } else {
        texture = idle;
    }
    velocity = {};

    Rectangle source{frame * width,0, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width , scale * height};
    DrawTexturePro(texture, source, dest, Vector2{},0.0, WHITE);
}