#pragma once
#include "GestAnim.h"
class Rotation :
    public GestAnim
{
private:
    float degreePerSecond;
    bool turnRight;

public:
    Rotation(GestAnimated* objet,float degreePerSecond, bool turnRight = false);
    void update(float deltaTime);
    void firstStart();
};

