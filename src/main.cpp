#include <iostream>
#include <raylib.h>
#include "colors.h"
#include "setup.h"
#include "game.h"

using Layout = std::vector<Object>;

int main() {
    InitWindow(2304, 1440, "GD");
    SetTargetFPS(60);

    int mode = 0;
    bool isMini = false;

    Game game = Game();
    Level lvl = game.GameStart(mode, isMini);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(darkBlue);
        
        game.Draw(lvl);
        lvl = game.Move(lvl);

        if (lvl.player.mode == -1) {
            WaitTime(0.5);
            lvl = game.GameStart(mode, isMini);
        }
        
        EndDrawing();
    }

    CloseWindow();
}
