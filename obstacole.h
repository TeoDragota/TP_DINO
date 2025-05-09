#ifndef OBSTACOLE_H
#define OBSTACOLE_H

#include "globals.h"
#include <stdbool.h>

#define MAX_OBSTACOLE 2

typedef struct {
    float x, y, width, height, speed;
    int type;       // tipul obstacolului
    bool active;
} Obstacol;

extern Obstacol obstacole[MAX_OBSTACOLE];

void initObstacole();
void updateObstacole();
void drawObstacole();

void initObstacol();
void updateObstacol();
void drawObstacol();

#endif
