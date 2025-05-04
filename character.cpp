#include "character.h"

Character::Character(){
    width = (float)texture.width / maxFrame;
    height = (float)texture.height;
}

void Character::setScreenPos(int winHeight, int winWidth){
    screenPos = {
        (float)winWidth / 2.0f - scale * (0.5f * (float)texture.width / 6),
        (float)winHeight / 2.0f - scale * (0.5f * (float)texture.height)
    };
}

void Character::tick(float dt){
    worldPosLastFrame = worldPos;
    texture = idle;
    Vector2 direction{};
    if (IsKeyDown(KEY_A)) direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) direction.x += 1.0;
    if (IsKeyDown(KEY_W)) direction.y -= 1.0;
    if (IsKeyDown(KEY_S)) direction.y += 1.0;
    if (Vector2Length(direction) != 0.0){
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos,Vector2Scale(Vector2Normalize(direction),speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
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

void Character::undoMovement(){
    worldPos = worldPosLastFrame;
}