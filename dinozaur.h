#ifndef DINOZAUR_H
#define DINOZAUR_H

#include "raylib.h"  

extern float dinoX, dinoY, dinoSize;
extern bool isJumping;
extern float jumpSpeed;
extern const float gravity;

extern Texture2D dinoTexture;  

void initDino();
void updateDino();
void drawDino();

#endif
