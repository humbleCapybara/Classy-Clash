#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "baseCharacter.h"
#include "character.h"

class Enemy : public baseCharacter{

public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    virtual void tick(float dt) override;
    virtual Vector2 getScreenPos() override;
    void setTarget(Character* object) { target = object; };
    
private:
    Character* target;
    float damagePerSec{10.f};
    float radius{60.f};
    float maxDistance{800.f};
};

#endif