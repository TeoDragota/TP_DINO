#include "dinozaur.h"
#include "raylib.h"
#include <stdbool.h>

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

    DrawCircle(dinoX + dinoSize / 2, dinoY + dinoSize / 2, dinoSize / 2, DARKGREEN);  // Corpul

    DrawCircle(dinoX + dinoSize * 1.5, dinoY + dinoSize / 2, dinoSize / 3, DARKGREEN);  // Capul

    DrawCircle(dinoX + dinoSize * 1.7, dinoY - 5, 5, RAYWHITE);  // Ochiul (alb)
    DrawCircle(dinoX + dinoSize * 1.7, dinoY - 5, 2, BLACK);  // Pupila (neagră)

    DrawLine(dinoX + dinoSize / 4, dinoY + dinoSize, dinoX + dinoSize / 4, dinoY + dinoSize + 10, DARKGREEN);  // Piciorul stâng
    DrawLine(dinoX + dinoSize * 0.75, dinoY + dinoSize, dinoX + dinoSize * 0.75, dinoY + dinoSize + 10, DARKGREEN);  // Piciorul drept

    DrawLine(dinoX + dinoSize / 2, dinoY + dinoSize * 1.2, dinoX + dinoSize / 2 - 10, dinoY + dinoSize * 1.4, DARKGREEN);  // Piciorul stâng spate
    DrawLine(dinoX + dinoSize * 1.2, dinoY + dinoSize * 1.2, dinoX + dinoSize * 1.2 + 10, dinoY + dinoSize * 1.4, DARKGREEN);  // Piciorul drept spate

    DrawLine(dinoX - 10, dinoY + dinoSize / 2, dinoX - 50, dinoY + dinoSize / 2 + 10, DARKGREEN);
}
