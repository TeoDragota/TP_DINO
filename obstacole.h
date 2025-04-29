#ifndef OBSTACOLE_H
#define OBSTACOLE_H

#include "raylib.h" 


extern float obstacle1X, obstacle1Y, obstacle1Width, obstacle1Height, obstacle1Speed;
extern float obstacle2X, obstacle2Y, obstacle2Radius;
extern int screenWidth, screenHeight, score; 


void initObstacol1();
void updateObstacol1();
void drawObstacol1();
bool checkCollisionWithDino1(float dinoX, float dinoY, float dinoSize);

void initObstacol2();
void updateObstacol2();
void drawObstacol2();
bool checkCollisionWithDino2(float dinoX, float dinoY, float dinoSize);

#endif
