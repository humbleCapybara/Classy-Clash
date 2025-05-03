#include "raylib.h"
#include "raymath.h"

int main(){
    const int windowWidth{ 384 };
    const int windowHeight( 384 );
    const int fps = 60;
    float speed = 4.0;
    float scale = 4.0;
    InitWindow(windowWidth, windowHeight, "Classy Clash");
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)windowWidth / 2.0f - scale * (0.5f * (float)knight.width / 6),
        (float)windowHeight / 2.0f - scale * (0.5f * (float)knight.height)
    };
    
    Vector2 mapPos = {0.0, 0.0};
    SetTargetFPS(fps);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(BLACK);
            Vector2 direction;
            if (IsKeyDown(KEY_A)) direction.x -= 1.0;
            if (IsKeyDown(KEY_D)) direction.x += 1.0;
            if (IsKeyDown(KEY_W)) direction.y -= 1.0;
            if (IsKeyDown(KEY_S)) direction.y += 1.0;
            if (Vector2Length(direction) != 0.0){
                // Set mapPos = mapPos - direction
                mapPos = Vector2Subtract(mapPos,Vector2Scale(Vector2Normalize(direction),speed));
            }
            DrawTextureEx(map, mapPos, 0, 4.0, WHITE);
        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(map);
    
}