#ifndef DINOZAUR_H
#define DINOZAUR_H

#include <stdbool.h>

extern float dinoX, dinoY, dinoSize;
extern bool isJumping;
extern float jumpSpeed;
extern int dinoSkin;


void initDino();
void updateDino();
void drawDino();

#endif
