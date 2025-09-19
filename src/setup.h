#pragma once
#include "colors.h"

#define SWING_PORTAL -8
#define SPIDER_PORTAL -7
#define ROBOT_PORTAL -6
#define WAVE_PORTAL -5
#define UFO_PORTAL -4
#define BALL_PORTAL -3
#define SHIP_PORTAL -2
#define CUBE_PORTAL -1
#define BLOCK 0
#define SPIKE 1
#define SLAB 2
#define HALF_SPIKE 3

struct Hitbox {
    Rectangle fatal;
    Rectangle safe;
};

struct Object {
    Vector2 pos;
    Hitbox hitbox;
    Color color;
    int type;
};

class Setup {

public:
    Setup();
    std::vector<Object> StereoMadness();
    std::vector<Object> MakeLayout();
    Object MakeBlock(
        Vector2 pos, Color color, int type
    );
    Hitbox MakeHitbox(int mode, bool mini);
    Rectangle MakeContact(int mode, bool mini);

private:
    float cellSize;
    std::vector<Color> colors;
};