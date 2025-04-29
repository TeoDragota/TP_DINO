#include "obstacole.h"
#include "raylib.h"
#include <stdio.h>

// Init obstacol1 (copac/cactus)
float obstacle1X = 800, obstacle1Y = 400, obstacle1Width = 20, obstacle1Height = 30, obstacle1Speed = 5;  // Dimensiuni mai mici

// INit obstacol2 (floare)
float obstacle2X = 1000, obstacle2Y = 400, obstacle2Radius = 15;  // Floare mai mică

void initObstacol1() {
    obstacle1X = screenWidth;  
    obstacle1Y = 400;
    obstacle1Width = 20;  
    obstacle1Height = 30; 
    obstacle1Speed = 5;
}

void updateObstacol1() {
    obstacle1X -= obstacle1Speed; 


    if (obstacle1X + obstacle1Width < 0) {
        obstacle1X = screenWidth;  
    }
}

void drawObstacol1() {

    DrawRectangle(obstacle1X, obstacle1Y - 30, obstacle1Width, obstacle1Height + 10, DARKBROWN);  // Cactus mai scund

    DrawRectangle(obstacle1X - 5, obstacle1Y - 40, 5, 15, DARKBROWN);  // Ramura stângă
    DrawRectangle(obstacle1X + obstacle1Width - 5, obstacle1Y - 40, 5, 15, DARKBROWN);  // Ramura dreaptă
}

bool checkCollisionWithDino1(float dinoX, float dinoY, float dinoSize) {
    Rectangle cactus = {obstacle1X, obstacle1Y - 40, obstacle1Width, obstacle1Height + 40};
    return CheckCollisionRecs((Rectangle){dinoX, dinoY, dinoSize, dinoSize}, cactus);
}

void initObstacol2() {
    obstacle2X = screenWidth + 200;
    obstacle2Y = 400;
    obstacle2Radius = 15; 
}

void updateObstacol2() {
    obstacle2X -= 5;  

    if (obstacle2X + obstacle2Radius * 2 < 0) {
        obstacle2X = screenWidth + 200; 
    }
}

void drawObstacol2() {
    DrawCircle(obstacle2X, obstacle2Y, obstacle2Radius, PURPLE); 
}

bool checkCollisionWithDino2(float dinoX, float dinoY, float dinoSize) {
    Vector2 floareCenter = {obstacle2X, obstacle2Y};
    return CheckCollisionCircleRec(floareCenter, obstacle2Radius, (Rectangle){dinoX, dinoY, dinoSize, dinoSize});
}
