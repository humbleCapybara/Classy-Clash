#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"
class baseCharacter{
public:
    baseCharacter();
    void undoMovement();
    Rectangle getCollisionRec();
    Vector2 getWorldPos(){return worldPos;};
    virtual void tick(float dt);

protected:
    int frame{};
    int maxFrame{6};
    float width{};
    float height{};
    float runningTime{};
    float updateTime{1.f/12.f};
    float rightLeft{1.f};
    Texture2D texture{};
    Texture2D idle{};
    Texture2D run{};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    float speed{4.f};
    float scale{4.f};
};

#endif