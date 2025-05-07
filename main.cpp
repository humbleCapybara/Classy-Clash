#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "enemy.h"
#include <string>

int main(){
    const int windowWidth{ 384 };
    const int windowHeight( 384 );
    const int fps = 60;
    InitWindow(windowWidth, windowHeight, "Classy Clash");
    // Loading Character
    Character knight{windowHeight,windowWidth};
    Enemy goblin{Vector2{500.f, 200.f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")};
    Enemy slime{Vector2{200.f, 500.f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")};

    Enemy* enemies[]{
        &goblin,
        &slime
    };

    for(auto enemy : enemies){
        enemy->setTarget(&knight);
    }

    // Loading textures
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos = {0.0, 0.0};

    // Loading Prop
    Prop props[2]{
        Prop{Vector2{600.f, 300.f},LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f},LoadTexture("nature_tileset/Log.png")}
    };

    const float mapScale = 4.f;
    SetTargetFPS(fps);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(WHITE);
            float dt = GetFrameTime();
            mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
            DrawTextureEx(map, mapPos, 0, mapScale, WHITE);

            // Draw the Props
            for (auto prop : props){
                prop.Render(knight.getWorldPos());
            }
            knight.tick(dt);
            
            for (auto enemy : enemies){
                enemy->tick(dt);
                if(CheckCollisionRecs(enemy->getCollisionRec(), knight.getWeaponCollisionRec())){
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE)) enemy->setAlive(false);
                }
            }
            
            // Check map bounds
            if (
                knight.getWorldPos().x < 0 ||
                knight.getWorldPos().y < 0 ||
                knight.getWorldPos().x + windowWidth > map.width * mapScale ||
                knight.getWorldPos().y + windowHeight > map.width * mapScale
            )
            {
                // Undo frame
                knight.undoMovement();
            }

            // Check for prop collision
            for (auto prop : props){
                if (CheckCollisionRecs(knight.getCollisionRec(),prop.getCollisionRec(knight.getWorldPos()))){
                    knight.undoMovement();
                }
            }
            
            if (!knight.getAlive()){
                DrawText("Game Over!", 55.f,45.f, 40, RED);
                EndDrawing();
                continue;
            }else{
                std::string prompt = "Health : ";
                prompt.append(std::to_string(knight.getHealth()),0,5);
                DrawText(prompt.c_str(), 10.f, 10.f, 20, RED);
            }

            

        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(map);
}