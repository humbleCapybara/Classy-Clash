#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "baseCharacter.h"

class Character : public baseCharacter{
    public:
        Character(int winHeight, int winWidth);
        virtual void tick(float dt) override;
        Vector2 getScreenPos(){return screenPos;};

    private:
};

#endif