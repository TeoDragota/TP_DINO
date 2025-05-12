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

        float speed = 3.0;

    if (score >= 12) speed = 3.6;
    else if (score >= 10) speed = 3.55;
    else if (score >= 8)  speed = 3.5;
    else if (score >= 6)  speed = 3.20;
    else if (score >= 4)  speed = 3.10;
    for (int i = 0; i < MAX_OBSTACOLE; i++) {
        if (obstacole[i].active) {
            obstacole[i].x -= obstacole[i].speed;
            obstacole[i].speed = speed;
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
        Color color;

    if (obstacole[i].type == 0) {
        // Tip 0 — dreptunghi
        if (score >= 12) color = LIME;
        else if (score >= 10) color = DARKBLUE;
        else if (score >= 8) color = GREEN;
        else if (score >= 6) color = DARKBROWN;
        else if (score >= 4) color = DARKGREEN;
        else if (score >= 2) color = BROWN;
        else color = DARKBROWN;
    } else {
        // Tip 1 — cub {
        if (score >= 12) color = (Color) {100, 0, 200, 255 }; //indigo
        else if (score >= 10) color = (Color){ 100, 100, 255, 255 };  // albastru închis
        else if (score >= 8) color = (Color){ 204, 153, 0, 255 }; //galben mustar
        else if (score >= 6) color = (Color){ 255, 150, 0, 255 }; //galben
        else if (score >= 4) color = DARKGRAY;
        else if (score >= 2) color = (Color){ 150, 150, 255, 255 }; //lila
        else color =  MAROON;
    }
   

    DrawRectangle(obstacole[i].x, obstacole[i].y,
                  obstacole[i].width, obstacole[i].height,
                  color);
}
}
