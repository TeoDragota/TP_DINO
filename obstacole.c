#include "obstacole.h"
#include "raylib.h"
#include "globals.h"
#include <stdlib.h>
#include <time.h>

Obstacol obstacole[MAX_OBSTACOLE];

void initObstacole() {
    srand(time(NULL));
    for (int i = 0; i < MAX_OBSTACOLE; i++) {
        obstacole[i].width = 20;
        obstacole[i].height = 40;
        obstacole[i].x = screenWidth + i * 400 + GetRandomValue(0, 200);
        obstacole[i].y = 400;
        obstacole[i].speed = 5;
        obstacole[i].type = GetRandomValue(0,1);
        obstacole[i].active = true;
        if (obstacole[i].type == 0) {
    obstacole[i].width = 20;
    obstacole[i].height = 40;
} else {
    obstacole[i].width = 30;
    obstacole[i].height = 30;
}
    }
}

void updateObstacole() {
    for (int i = 0; i < MAX_OBSTACOLE; i++) {
        if (obstacole[i].active) {
            obstacole[i].x -= obstacole[i].speed;

            if (obstacole[i].x + obstacole[i].width < 0) {
                obstacole[i].x = screenWidth + GetRandomValue(0, 300);
                score++;
            }
        }
    }
}

void drawObstacole() {
    for (int i = 0; i < MAX_OBSTACOLE; i++) {
        if (obstacole[i].active) {
            Color color = (obstacole[i].type == 0) ? DARKBROWN : MAROON;
            DrawRectangle(obstacole[i].x, obstacole[i].y, obstacole[i].width, obstacole[i].height, color);
            
        }
    }
}
