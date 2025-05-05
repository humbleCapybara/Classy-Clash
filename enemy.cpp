#include "Enemy.h"
#include "raymath.h"

Enemy :: Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    worldPos = pos;

    width = static_cast<float>(texture.width) / maxFrame;
    height = static_cast<float>(texture.height);

    speed = 3.f;
}

void Enemy :: tick(float dt){

    // Get toTarget
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(),screenPos);

    // Normalize toTarget
    toTarget = Vector2Normalize(toTarget);

    // Multiply toTarget by speed
    toTarget = Vector2Scale(toTarget, speed);

    // Move Enemy
    worldPos = Vector2Add(worldPos, toTarget);

    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    baseCharacter::tick(dt);
}