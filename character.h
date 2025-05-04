#include "raylib.h"
#include "raymath.h"

class Character{
    public:
        Character();
        Vector2 getWorldPos(){ return worldPos; }
        void undoMovement();
        void setScreenPos(int winHeight, int winWidth);
        void tick(float dt);
    
    private:
        int frame{};
        int maxFrame{6};
        float width{};
        float height{};
        float runningTime{};
        float updateTime{1.f/12.f};
        float rightLeft{1.f};
        Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};
        float speed{4.f};
        float scale{4.f};
    };