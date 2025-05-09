#include "dinozaur.h"
#include "raylib.h"

float dinoX = 100, dinoY = 400, dinoSize = 40;
bool isJumping = false;
float jumpSpeed = 0;
const float gravity = 0.5;

void initDino() {
    dinoX = 100;
    dinoY = 400;
    dinoSize = 40;
    isJumping = false;
    jumpSpeed = 0;
}

void updateDino() {
    if (IsKeyPressed(KEY_SPACE) && !isJumping) {
        isJumping = true;
        jumpSpeed = -10;
    }

    if (isJumping) {
        dinoY += jumpSpeed;
        jumpSpeed += gravity;

        if (dinoY >= 400) {
            dinoY = 400;
            isJumping = false;
        }
    }
}

void drawDino() {
    DrawRectangle(dinoX, dinoY, dinoSize, dinoSize, DARKGREEN);
}
