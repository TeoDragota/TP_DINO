#include "obstacole.h"
#include "raylib.h"
#include <stdio.h>

float obstacle1X = 800, obstacle1Y = 400, obstacle1Width = 30, obstacle1Height = 50, obstacle1Speed = 5;

void initObstacol1() {
    obstacle1X = screenWidth;
    obstacle1Y = 400;
    obstacle1Width = 30;
    obstacle1Height = 50;
    obstacle1Speed = 5;
}

void updateObstacol1() {
    obstacle1X -= obstacle1Speed;  // Muta obstacolul spre stânga

    // Dacă obstacolul a trecut de dinozaur, repoziționează-l
    if (obstacle1X + obstacle1Width < 0) {
        obstacle1X = screenWidth;
    }
}

void drawObstacol1() {
    // Desenăm cactusul (obstacol maro)
    DrawRectangle(obstacle1X, obstacle1Y - 40, obstacle1Width, obstacle1Height + 10, DARKBROWN);  // Cactus mai scund

    // Ramurile cactusului
    DrawRectangle(obstacle1X - 5, obstacle1Y - 50, 5, 20, DARKBROWN);  // Ramura stângă
    DrawRectangle(obstacle1X + obstacle1Width - 5, obstacle1Y - 50, 5, 20, DARKBROWN);  // Ramura dreaptă
}

bool checkCollisionWithDino1(float dinoX, float dinoY, float dinoSize) {
    // Coliziune cu cactusul
    Rectangle cactus = {obstacle1X, obstacle1Y - 40, obstacle1Width, obstacle1Height + 40};
    return CheckCollisionRecs((Rectangle){dinoX, dinoY, dinoSize, dinoSize}, cactus);
}
