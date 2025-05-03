#include "raylib.h"
#include "raymath.h"

int main(){
    const int windowWidth{ 384 };
    const int windowHeight( 384 );
    const int fps = 60;
    float speed = 4.0;
    float scale = 4.0;
    int frame{};
    const int maxFrame{6};
    float runningTime{};
    const float updateTime{1.f/12.f};
    InitWindow(windowWidth, windowHeight, "Classy Clash");
    // Loading textures
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Texture2D knight;
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    float rightLeft{1.f};
    Vector2 knightPos{
        (float)windowWidth / 2.0f - scale * (0.5f * (float)knight_idle.width / 6),
        (float)windowHeight / 2.0f - scale * (0.5f * (float)knight_idle.height)
    };
    Vector2 mapPos = {0.0, 0.0};
    SetTargetFPS(fps);
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(WHITE);
            float dt = GetFrameTime();
            bool idle = true;
            Vector2 direction{};
            if (IsKeyDown(KEY_A)) direction.x -= 1.0;
            if (IsKeyDown(KEY_D)) direction.x += 1.0;
            if (IsKeyDown(KEY_W)) direction.y -= 1.0;
            if (IsKeyDown(KEY_S)) direction.y += 1.0;
            if (Vector2Length(direction) != 0.0){
                // Set mapPos = mapPos - direction
                mapPos = Vector2Subtract(mapPos,Vector2Scale(Vector2Normalize(direction),speed));
                direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
                idle = false;
            }
            DrawTextureEx(map, mapPos, 0, 4.0, WHITE);

            if (idle) knight = knight_idle;
            else knight = knight_run;

            runningTime += dt;
            if (runningTime >= updateTime){
                runningTime = 0.0f;
                frame++;
                if (frame > maxFrame){
                    frame = 0;
                }
            }
            
            Rectangle knightSourceRec{frame * (float)knight.width / 6.0f,0,rightLeft * (float)knight.width / 6.0f,(float)knight.height};

            Rectangle knightDestinationRec{
                knightPos.x,
                knightPos.y,
                4.0f * (float)knight.width/6,
                4.0f * (float)knight.height
            };
            
            DrawTexturePro(knight, knightSourceRec, knightDestinationRec, Vector2{},0.0, WHITE);
            
            
        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(map);
    UnloadTexture(knight_idle);
    UnloadTexture(knight_run);

}