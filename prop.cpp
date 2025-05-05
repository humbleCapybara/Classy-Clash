#include "prop.h"
#include "raymath.h"

Prop :: Prop(Vector2 pos, Texture2D tex) : 
    texture(tex),
    worldPos(pos) 
{
    
}

void Prop :: Render(Vector2 knightPos){
    Vector2 screenPos = Vector2Subtract(worldPos, knightPos);
    DrawTextureEx(texture, screenPos, 0.0f, scale, WHITE);
}

Rectangle Prop :: getCollisionRec(Vector2 knightPos){
    Vector2 screenPos{
        Vector2Subtract(worldPos, knightPos)
    };
    return Rectangle{
        screenPos.x + 20,
        screenPos.y + 20,
        (static_cast<float>(texture.width) * scale) - 40,
        (static_cast<float>(texture.height) * scale) - 40
    };
}