#include "setup.h"
#include <iostream>
#include <algorithm>
#include <cassert>

Setup::Setup() {
    cellSize = 144;
    colors = GetCellColors();
}

std::vector<Object> Setup::StereoMadness() {
    std::vector<Object> layout;
    layout.push_back(MakeBlock({20, 7}, blue, SPIKE));
    layout.push_back(MakeBlock({30, 7}, blue, HALF_SPIKE));
    layout.push_back(MakeBlock({31, 7}, blue, SPIKE));
    layout.push_back(MakeBlock({40, 7}, blue, SPIKE));
    layout.push_back(MakeBlock({41, 7}, blue, SPIKE));
    layout.push_back(MakeBlock({42, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({46, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({46, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({50, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({50, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({50, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({60, 7}, blue, SPIKE));
    layout.push_back(MakeBlock({61, 7}, blue, SPIKE));
    layout.push_back(MakeBlock({68, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({69, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({70, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({71, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({72, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({73, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({74, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({75, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({76, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({80, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({81, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({82, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({83, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({84, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({85, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({85, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({86, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({87, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({88, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({89, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({90, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({94, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({94, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({95, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({95, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({96, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({96, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({97, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({97, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({98, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({98, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({99, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({99, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({100, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({100, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({100, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({100, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({101, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({101, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({101, 5}, blue, SPIKE));
    layout.push_back(MakeBlock({102, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({102, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({103, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({103, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({104, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({104, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({105, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({105, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({106, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({106, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({107, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({107, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({111, 5}, blue, SLAB));
    layout.push_back(MakeBlock({115, 4}, blue, SLAB));
    layout.push_back(MakeBlock({119, 3}, blue, SLAB));
    layout.push_back(MakeBlock({123, 2}, blue, SLAB));
    layout.push_back(MakeBlock({127, 1}, blue, SLAB));

    layout.push_back(MakeBlock({133, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({134, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({135, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({136, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({137, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({138, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({139, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({139, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({140, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({140, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({140, 5}, blue, SLAB));
    layout.push_back(MakeBlock({141, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({141, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({141, 5}, blue, SLAB));
    layout.push_back(MakeBlock({142, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({142, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({143, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({144, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({145, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({146, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({147, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({147, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({148, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({148, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({148, 5}, blue, SLAB));
    layout.push_back(MakeBlock({149, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({149, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({149, 5}, blue, SLAB));
    layout.push_back(MakeBlock({150, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({150, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({151, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({152, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({153, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({154, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({158, 6}, blue, SLAB));
    layout.push_back(MakeBlock({158, 5}, blue, SPIKE));
    layout.push_back(MakeBlock({159, 6}, blue, SLAB));
    layout.push_back(MakeBlock({159, 5}, blue, SPIKE));
    layout.push_back(MakeBlock({160, 6}, blue, SLAB));
    layout.push_back(MakeBlock({160, 5}, blue, SPIKE));
    layout.push_back(MakeBlock({161, 6}, blue, SLAB));
    layout.push_back(MakeBlock({161, 5}, blue, SPIKE));
    layout.push_back(MakeBlock({165, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({166, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({167, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({168, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({169, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({169, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({170, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({170, 6}, blue, SPIKE));
    layout.push_back(MakeBlock({171, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({172, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({173, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({174, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({175, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({176, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({177, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({178, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({179, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({180, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({182, 5}, blue, SLAB));
    layout.push_back(MakeBlock({183, 5}, blue, SLAB));
    layout.push_back(MakeBlock({184, 5}, blue, SLAB));
    layout.push_back(MakeBlock({185, 5}, blue, SLAB));
    layout.push_back(MakeBlock({185, 4}, blue, SPIKE));
    layout.push_back(MakeBlock({187, 6}, blue, SLAB));
    layout.push_back(MakeBlock({188, 6}, blue, SLAB));
    layout.push_back(MakeBlock({189, 6}, blue, SLAB));
    layout.push_back(MakeBlock({190, 6}, blue, SLAB));
    layout.push_back(MakeBlock({191, 6}, blue, SLAB));
    layout.push_back(MakeBlock({192, 6}, blue, SLAB));
    layout.push_back(MakeBlock({193, 6}, blue, SLAB));
    layout.push_back(MakeBlock({193, 5}, blue, SPIKE));
    layout.push_back(MakeBlock({195, 7}, blue, SLAB));
    layout.push_back(MakeBlock({196, 7}, blue, SLAB));
    layout.push_back(MakeBlock({197, 7}, blue, SLAB));
    layout.push_back(MakeBlock({198, 7}, blue, SLAB));
    layout.push_back(MakeBlock({199, 7}, blue, SLAB));
    layout.push_back(MakeBlock({203, 6}, blue, SLAB));
    layout.push_back(MakeBlock({207, 5}, blue, SLAB));
    layout.push_back(MakeBlock({211, 4}, blue, SLAB));
    layout.push_back(MakeBlock({215, 3}, blue, SLAB));
    layout.push_back(MakeBlock({219, 2}, blue, SLAB));
    layout.push_back(MakeBlock({221, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({222, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({223, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({223, 1}, blue, SLAB));
    layout.push_back(MakeBlock({223, 0}, blue, SPIKE));
    layout.push_back(MakeBlock({224, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({225, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({226, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({227, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({228, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({228, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({228, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({228, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({228, 0}, blue, BLOCK));
    layout.push_back(MakeBlock({229, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({229, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({229, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({229, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({229, 0}, blue, BLOCK));
    layout.push_back(MakeBlock({230, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({230, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({230, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({230, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({230, 0}, blue, BLOCK));
    layout.push_back(MakeBlock({231, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({231, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({231, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({231, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({231, 0}, blue, BLOCK));
    layout.push_back(MakeBlock({232, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({232, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({232, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({232, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({232, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({233, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({233, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({233, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({233, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({233, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({233, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({234, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({234, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({234, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({234, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({234, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({234, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({235, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({235, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({235, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({235, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({235, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({235, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({236, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({236, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({236, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({236, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({236, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({236, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({237, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({237, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({237, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({237, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({237, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({237, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({238, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({238, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({238, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({238, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({238, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({238, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({239, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({239, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({239, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({239, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({239, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({239, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({240, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({240, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({240, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({240, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({240, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({240, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({241, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({241, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({241, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({241, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({241, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({241, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({242, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({242, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({242, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({242, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({242, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({242, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({243, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({243, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({243, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({243, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({243, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({243, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({244, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({244, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({244, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({244, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({244, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({244, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({245, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({245, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({245, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({245, 2}, blue, BLOCK));
    layout.push_back(MakeBlock({245, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({245, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({246, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({246, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({246, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({246, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({246, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({247, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({247, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({247, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({247, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({247, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({248, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({248, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({248, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({248, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({248, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({249, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({249, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({249, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({249, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({249, 0}, blue, BLOCK));

    layout.push_back(MakeBlock({250, 7}, blue, BLOCK));
    layout.push_back(MakeBlock({250, 6}, blue, BLOCK));
    layout.push_back(MakeBlock({250, 5}, blue, BLOCK));
    layout.push_back(MakeBlock({250, 1}, blue, BLOCK));
    layout.push_back(MakeBlock({250, 0}, blue, BLOCK));

    return layout;
}

std::vector<Object> Setup::MakeLayout() {
    std::vector<Object> layout = StereoMadness();
    // layout.push_back(MakeBlock({40, 7}, red, BLOCK));
    // layout.push_back(MakeBlock({41, 7}, red, BLOCK));
    // layout.push_back(MakeBlock({42, 7}, red, BLOCK));
    // layout.push_back(MakeBlock({60, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({90, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({91, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({92, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({65, 4}, red, SLAB));
    // layout.push_back(MakeBlock({96, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({96.75, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({97.5, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({98.25, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({102, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({103, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({104, 7}, red, SPIKE));
    // layout.push_back(MakeBlock({62, 6}, green, BLOCK));
    // layout.push_back(MakeBlock({65, 4}, red, SLAB));
    // layout.push_back(MakeBlock({61, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({62, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({63, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({64, 7}, green, HALF_SPIKE));
    // layout.push_back(MakeBlock({65, 7}, green, HALF_SPIKE));

    std::sort(
        begin(layout), end(layout),
        [](auto a, auto b) {
            if (a.pos.x != b.pos.x) {
                return a.pos.x > b.pos.x;
            } else {
                return a.pos.y < b.pos.y;
            }
        }
    );

    return layout;
}

Object Setup::MakeBlock(
    Vector2 pos, Color color, int type
) {
    switch (type) {
        case 0:
        return {
            { pos.x * cellSize, pos.y * cellSize + 1 },
            {
                Rectangle{
                    pos.x * cellSize + 10, pos.y * cellSize + 11,
                    cellSize - 20, cellSize - 20
                },
                Rectangle{
                    pos.x * cellSize + 10, pos.y * cellSize + 1,   
                    cellSize - 20, 5
                }
            },
            color,
            0
        };
        case 1:
        return {
            { pos.x * cellSize, pos.y * cellSize + 1 },
            {
                Rectangle{
                    (pos.x * cellSize) + cellSize / 3,
                    (pos.y * cellSize) + cellSize / 3,
                    cellSize / 3, cellSize / 2
                },
                {0, 0, 0, 0}
            },
            color,
            1
        };
        case 2:
        return {
            { pos.x * cellSize, pos.y * cellSize + 1 },
            {
                Rectangle{
                    pos.x * cellSize + 10, pos.y * cellSize + 11,
                    cellSize - 20, (cellSize / 2) - 20
                },
                Rectangle{
                    pos.x * cellSize + 10, pos.y * cellSize + 1,
                    cellSize - 20, 5
                }
            },
            color,
            2
        };
        case 3:
        return {
            { pos.x * cellSize, pos.y * cellSize + 1 },
            {
                Rectangle{
                    (pos.x * cellSize) + cellSize / 3,
                    (pos.y * cellSize) + 2 * (cellSize / 3),
                    cellSize / 3, cellSize / 6
                },
                {0, 0, 0, 0}
            },
            color,
            3
        };
        default:
        return {
            { pos.x * cellSize, pos.y * cellSize + 1 },
            {
                Rectangle{
                    pos.x * cellSize + 10, pos.y * cellSize + 11,
                    cellSize - 20, cellSize - 20
                },
                Rectangle{
                    pos.x * cellSize + 10, pos.y * cellSize + 1,   
                    cellSize - 20, 5
                }
            },
            color,
            0
        };
    }
}

Hitbox Setup::MakeHitbox(int mode, bool mini) {
    switch(mode) {
        case 0:
        return {
            Rectangle {
                5 * cellSize + 11,
                7 * cellSize + 11,
                cellSize - 20,
                cellSize - 20
            },
            Rectangle {
                5 * cellSize + 11,
                8 * cellSize - 4,
                cellSize - 20,
                5
            }
        };
        case 1:
        default:
        return {
            Rectangle {
                5 * cellSize + 6,
                7 * cellSize + 6,
                cellSize - 10,
                cellSize - 10
            },
            Rectangle {
                5 * cellSize + 6,
                8 * cellSize - 4,
                cellSize - 10,
                5
            }
        };
    }
}