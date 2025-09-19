#include <iostream>
#include "colors.h"
#include "game.h"
#include "setup.h"
#include <vector>
#include <cmath>

Game::Game() {
    numRows = 10;
    numCols = 17;
    Initialize();
    cellSize = 144;
    colors = GetCellColors();
    cubeJump = {
        1.0 / 3.0, 1.0 / 4.0,
        1.0 / 8.0, 1.0 / 14.4,
        1.0 / 24.0
    };
    cubeFall = {
        1.0 / 24.0, 1.0 / 14.4,
        1.0 / 8.0, 1.0 / 4.0,
        1.0 / 3.0, 1.0 / 2.4,
        1.0 / 1.8, 1.0 / 1.6,
        1.0 / 1.2, 1.0
    };
}

Level Game::GameStart(int mode, bool isMini) {
    Setup setup = Setup();

    std::vector<Object> layout = setup.MakeLayout();
    Hitbox hitbox = setup.MakeHitbox(mode, isMini);

    State state = {layout, {16, 7}, oneX};
    Player player = {
        {5 * cellSize, 7 * cellSize}, hitbox, 0, 0
    };
    
    return { state, player };
}

void Game::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (row < numRows - 2) {
                background[row][col] = 0;
            } else {
                background[row][col] = 2;
            }
        }
    }
}

void Game::Draw(Level lvl) {
    Initialize();
    DrawGrid(lvl.state.grid);
    DrawLayout(lvl.state);
    DrawPlayer(lvl.player);
}

void Game::DrawGrid(Vector2 grid) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int cellValue = background[row][col];
            float offsetX = (
                grid.x - std::floor(grid.x)
            );
            float offsetY = (
                grid.y - std::floor(grid.y)
            );
            DrawRectangle(
                (col - offsetX) * cellSize + 1,
                (row + offsetY) * cellSize + 1,
                cellSize - 1, cellSize - 1,
                colors[cellValue]
            );
        }
    }
}

void Game::DrawLayout(State state) {
    float border = (
        state.grid.x * (float)cellSize
    );

    int size = (state.layout).size();
    for (int i = size - 1; i >= 0; i--) {
        if (border >= (state.layout)[i].pos.x) {
            DrawBlock((state.layout)[i]);
        } else {
            break;
        }
    }
}

void Game::DrawBlock(Object block) {
    Vector2 pos = block.pos;
    switch (block.type) {
        case 0:
        DrawRectangle(
            pos.x, pos.y,
            cellSize - 1, cellSize - 1,
            block.color
        );
        break;
        case 1:
        DrawTriangle(
            { pos.x + cellSize - 1, pos.y + cellSize },
            { pos.x + (cellSize / 2), pos.y},
            { pos.x, pos.y + cellSize},
            block.color
        );
        break;
        case 2:
        DrawRectangle(
            pos.x, pos.y,
            cellSize - 1, (cellSize / 2) - 1,
            block.color
        );
        break;
        case 3:
        DrawTriangle(
            { pos.x + cellSize - 1, pos.y + cellSize },
            { pos.x + (cellSize / 2), pos.y + (cellSize / 2) },
            { pos.x, pos.y + cellSize},
            block.color
        );
        break;
        default:
        DrawRectangle(
            pos.x, pos.y,
            cellSize - 1, cellSize - 1,
            block.color
        );
    }

    DrawRectangleLinesEx(
        block.hitbox.fatal, 5, colors[6]
    );
    DrawRectangleLinesEx(
        block.hitbox.safe, 5, colors[7]
    );
}

void Game::DrawPlayer(Player player) {
    switch(player.mode) {
        case 0:
        DrawRectangle(
            player.pos.x + 1,
            player.pos.y + 1,
            cellSize, cellSize, colors[6]
        );
        DrawRectangleLinesEx(player.hitbox.fatal, 5, colors[4]);
        DrawRectangleLinesEx(player.hitbox.safe, 5, colors[7]);
        break;
        case 1:
        break;
        default:
        DrawRectangle(
            player.pos.x + 1,
            player.pos.y + 1,
            cellSize, cellSize, colors[6]
        );
        DrawRectangleLinesEx(player.hitbox.fatal, 5, colors[4]);
        DrawRectangleLinesEx(player.hitbox.safe, 5, colors[7]);
    }
}

bool Game::GameEnd(Level lvl, int i) {
    bool crash = CheckCollisionRecs(
        (lvl.state.layout)[i].hitbox.fatal,
        lvl.player.hitbox.fatal
    );

    if (crash) {
        return true;
    }

    return false;
}

bool Game::Contact(Level lvl, int i) {
    bool contact = CheckCollisionRecs(
        (lvl.state.layout)[i].hitbox.safe,
        lvl.player.hitbox.safe
    );
    
    if (contact) {
        return true;
    }

    return false;
}

Level Game::Move(Level lvl) {
    lvl.state.grid.x += lvl.state.speed / cellSize;
    int size = (lvl.state.layout).size();
    bool falling = true;
    for (int i = 0; i < size; i++) {
        (lvl.state.layout)[i].pos.x -= lvl.state.speed;
        (lvl.state.layout)[i].hitbox.fatal.x -= lvl.state.speed;
        (lvl.state.layout)[i].hitbox.safe.x -= lvl.state.speed;
        
        if ((lvl.state.layout)[i].pos.x < -(cellSize)) {
            (lvl.state.layout).erase((lvl.state.layout).end());
        }

        if ((lvl.state.layout)[i].pos.x < 4 * cellSize ||
            (lvl.state.layout)[i].pos.x > 6 * cellSize) {
            continue;
        }

        if (GameEnd(lvl, i)) {
            lvl.player.mode = -1;
            return lvl;
        }

        if (Contact(lvl, i)) {
            lvl.player.frame = 0;
            falling = false;
        }

        if ((lvl.state.layout)[i].type < 0) {
            lvl.player.mode = -((lvl.state.layout)[i].type);
        }
    }

    if (falling && lvl.player.frame == 0 &&
        lvl.player.pos.y < 7 * cellSize) {
        lvl.player.frame--;
    }

    if (GetClick(lvl.player) || lvl.player.frame > 0) {
        lvl.player.frame++;
        lvl.player = DoJump(lvl);
    }

    if (lvl.player.frame < 0) {
        lvl.player.frame--;
        lvl.player = DoFall(lvl);
    }

    return lvl;
}

bool Game::GetClick(Player player) {
    if (!player.frame && (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP) ||
        IsKeyDown(KEY_W) || IsMouseButtonDown(0))) {
        return true;
    }
    return false;
}

Player Game::DoJump(Level lvl) {
    switch(lvl.player.mode) {
        case 0:
        if (lvl.player.frame <= 14) {
            int distance = cellSize * cubeJump[lvl.player.frame / 3];
            for (int i = 0; i < distance; i++) {
                lvl.player.pos.y--;
                lvl.player.hitbox.fatal.y--;
                lvl.player.hitbox.safe.y--;
                int size = (lvl.state.layout).size();
                for (int i = 0; i < size; i++) {
                    bool contact = CheckCollisionRecs(
                        (lvl.state.layout)[i].hitbox.safe,
                        lvl.player.hitbox.safe
                    );
                    if (contact) {
                        return lvl.player;
                    }
                }
            }
        } else {
            lvl.player.frame = -1;
        }
        break;
        case 1:
        break;
        default:
        if (lvl.player.frame <= 14) {
            int distance = cellSize * cubeJump[lvl.player.frame / 3];
            for (int i = 0; i < distance; i++) {
                lvl.player.pos.y--;
                lvl.player.hitbox.fatal.y--;
                lvl.player.hitbox.safe.y--;
                int size = (lvl.state.layout).size();
                for (int i = 0; i < size; i++) {
                    bool contact = CheckCollisionRecs(
                        (lvl.state.layout)[i].hitbox.safe,
                        lvl.player.hitbox.safe
                    );
                    if (contact) {
                        return lvl.player;
                    }
                }
            }
        } else {
            lvl.player.frame = -1;
        }
    }
    
    return lvl.player;
}

Player Game::DoFall(Level lvl) {
    int distance = cellSize * cubeFall[-(lvl.player.frame) / 3];
    switch(lvl.player.mode) {
        case 0:
        for (int i = 0; i < distance; i++) {
            if (lvl.player.pos.y >= 7 * cellSize) {
                lvl.player.frame = 0;
                break;
            }
            lvl.player.pos.y++;
            lvl.player.hitbox.fatal.y++;
            lvl.player.hitbox.safe.y++;
            int size = (lvl.state.layout).size();
            for (int i = 0; i < size; i++) {
                bool contact = CheckCollisionRecs(
                    (lvl.state.layout)[i].hitbox.safe,
                    lvl.player.hitbox.safe
                );
                if (contact) {
                    return lvl.player;
                }
            }
        }
        break;
        case 1:
        break;
        default:
        for (int i = 0; i < distance; i++) {
            lvl.player.pos.y++;
            lvl.player.hitbox.fatal.y++;
            lvl.player.hitbox.safe.y++;
            int size = (lvl.state.layout).size();
            for (int i = 0; i < size; i++) {
                if ((lvl.state.layout)[i].hitbox.safe.x > 6) {
                    break;
                }
                bool contact = CheckCollisionRecs(
                    (lvl.state.layout)[i].hitbox.safe,
                    lvl.player.hitbox.safe
                );
                if (contact) {
                    return lvl.player;
                }
            }
        }
    }
    
    return lvl.player;
}