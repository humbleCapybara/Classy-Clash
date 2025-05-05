#include "baseCharacter.h"

baseCharacter :: baseCharacter(){

}

void baseCharacter :: undoMovement(){
    worldPos = worldPosLastFrame;
}

Rectangle baseCharacter :: getCollisionRec(){
    return Rectangle{
        screenPos.x,
        screenPos.y,
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
        if (frame > maxFrame){
            frame = 0;
        }
    }

    Rectangle source{frame * width,0, rightLeft * width, height};
    Rectangle dest{screenPos.x,screenPos.y, scale * width , scale * height};
    DrawTexturePro(texture, source, dest, Vector2{},0.0, WHITE);
}