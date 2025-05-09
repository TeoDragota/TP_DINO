#include "obstacole.h"
#include "raylib.h"

float obstacleX = 800, obstacleY = 400, obstacleWidth = 20, obstacleHeight = 40, obstacleSpeed = 5;

void initObstacol() {
    obstacleX = screenWidth;
    obstacleY = 400;
    obstacleWidth = 20;
    obstacleHeight = 40;
    obstacleSpeed = 5;
}

void updateObstacol() {
    obstacleX -= obstacleSpeed;
}

void drawObstacol() {
    DrawRectangle(obstacleX, obstacleY, obstacleWidth, obstacleHeight, DARKBROWN);
}
