#include "character.h"

Character::Character(int winHeight, int winWidth){

    texture = LoadTexture("characters/knight_idle_spritesheet.png");
    idle = LoadTexture("characters/knight_idle_spritesheet.png");
    run = LoadTexture("characters/knight_run_spritesheet.png");

    width = static_cast<float>(texture.width) / maxFrame;
    height = static_cast<float>(texture.height);

    screenPos = {
        static_cast<float>(winWidth) / 2.0f - scale * (0.5f * static_cast<float>(texture.width) / 6),
        static_cast<float>(winHeight) / 2.0f - scale * (0.5f * static_cast<float>(texture.height))
    };

}

void Character::tick(float dt){

    // Parently stuff
    baseCharacter::tick(dt);

    // Childy stuff
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

    
    
}