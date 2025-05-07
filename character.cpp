#include "character.h"
#include "raylib.h"

Character::Character(int winHeight, int winWidth) :
    windowHeight(winHeight),
    windowWidth(winWidth)
{

    texture = LoadTexture("characters/knight_idle_spritesheet.png");
    idle = LoadTexture("characters/knight_idle_spritesheet.png");
    run = LoadTexture("characters/knight_run_spritesheet.png");

    width = static_cast<float>(texture.width) / maxFrame;
    height = static_cast<float>(texture.height);

}

Vector2 Character :: getScreenPos(){
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * static_cast<float>(texture.width) / 6),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * static_cast<float>(texture.height))
    };
}
void Character::tick(float dt){
    if (!getAlive()) return;

    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0; 

    // Parently stuff
    baseCharacter::tick(dt);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.f){
        origin = {0.f , weapon.height * scale};
        offset = {35.5f, 55.5f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_SPACE) ? 35.f : 0.f;
    }else{
        origin = {weapon.width * scale , weapon.height * scale};
        offset = {25.5f,55.5f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_SPACE) ? -35.f : 0.f;
    }

    // Draw the sword
    Rectangle source{0.f,0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);
}

void Character :: takeDamage(float damage){
    health -= damage;
    if (health < 0.f){
        setAlive(false);
    }
}