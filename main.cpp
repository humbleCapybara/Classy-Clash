#include "character.h"

int main(){
    const int windowWidth{ 384 };
    const int windowHeight( 384 );
    const int fps = 60;
    InitWindow(windowWidth, windowHeight, "Classy Clash");
    // Loading Character
    Character knight;
    knight.setScreenPos(windowHeight,windowWidth);

    // Loading textures
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos = {0.0, 0.0};
    const float mapScale = 4.f;
    SetTargetFPS(fps);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(WHITE);
            float dt = GetFrameTime();
            mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
            DrawTextureEx(map, mapPos, 0, mapScale, WHITE);
            knight.tick(dt);

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
        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(map);
}