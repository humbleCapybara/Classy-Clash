#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "baseCharacter.h"

class Character : public baseCharacter{
    public:
        Character(int winHeight, int winWidth);
        virtual void tick(float dt) override;
        virtual Vector2 getScreenPos() override;
        Rectangle getWeaponCollisionRec(){ return weaponCollisionRec; };
        float getHealth() const { return health; };
        void takeDamage(float damage);
    private:
        float windowHeight;
        float windowWidth;
        Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
        Rectangle weaponCollisionRec{};
        float health{100.f};
};

#endif