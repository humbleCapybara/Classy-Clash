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

    speed = 2.f;
}

Vector2 Enemy :: getScreenPos(){
    return Vector2Subtract(worldPos, target->getWorldPos());
}
void Enemy :: tick(float dt){
    if (!getAlive()) return;
    // Get velocity of enemy
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    if (Vector2Length(velocity) < radius){
        velocity = {};
    }
    if (Vector2Length(velocity) > maxDistance){
        velocity = {};
    }
    baseCharacter::tick(dt);
    if(CheckCollisionRecs(getCollisionRec(), target->getCollisionRec())){
        target->takeDamage(damagePerSec * dt);
    }
}
