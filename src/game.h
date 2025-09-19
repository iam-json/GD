#pragma once
#include "setup.h"

#define CUBE 0
#define SHIP 1
#define BALL 2
#define UFO 3
#define WAVE 4
#define ROBOT 5
#define SPIDER 6
#define SWING 7

#define halfX 18
#define oneX 24
#define twoX 28.8
#define threeX 36
#define fourX 48

struct State {
    std::vector<Object> layout;
    Vector2 grid;
    float speed;
};

struct Player {
    Vector2 pos;
    Hitbox hitbox;
    int mode;
    int frame;
};

struct Level {
    State state;
    Player player;
};

class Game {
public:
    Game();
    bool GameEnd(Level lvl, int i);
    bool Contact(Level lvl, int i);
    Level GameStart(int mode, bool isMini);
    void Initialize();
    void Draw(Level lvl);
    void DrawGrid(Vector2 grid);
    void DrawLayout(State state);
    void DrawBlock(Object block);
    void DrawPlayer(Player player);
    int background[10][17];
    Level Move(Level lvl);
    Player DoJump(Level lvl);
    Player DoFall(Level lvl);
    bool GetClick(Player player);

private:
    int numRows;
    int numCols;
    float cellSize;
    std::vector<Color> colors;
    std::vector<float> cubeJump;
    std::vector<float> cubeFall;
};