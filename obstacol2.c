#include "obstacole.h"
#include "raylib.h"
#include <stdio.h>

float obstacle2X = 1000, obstacle2Y = 400, obstacle2Radius = 20;

void initObstacol2() {
    obstacle2X = screenWidth + 200;
    obstacle2Y = 400;
    obstacle2Radius = 20;
}

void updateObstacol2() {
    obstacle2X -= 5;  // Muta obstacolul floare spre stânga

    // Dacă floarea a trecut de dinozaur, repoziționează-o
    if (obstacle2X + obstacle2Radius * 2 < 0) {
        obstacle2X = screenWidth + 200;
    }
}

void drawObstacol2() {
    // Desenăm floarea simplificată (cerc mov)
    DrawCircle(obstacle2X, obstacle2Y, obstacle2Radius, PURPLE);  // Floare simplificată
}

bool checkCollisionWithDino2(float dinoX, float dinoY, float dinoSize) {
    // Coliziune cu floarea (cerc)
    Vector2 floareCenter = {obstacle2X, obstacle2Y};
    return CheckCollisionCircleRec(floareCenter, obstacle2Radius, (Rectangle){dinoX, dinoY, dinoSize, dinoSize});
}
