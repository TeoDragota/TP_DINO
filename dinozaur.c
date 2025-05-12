#include "dinozaur.h"
#include "raylib.h"

float dinoX = 100, dinoY = 400, dinoSize = 40;
bool isJumping = false;
float jumpSpeed = 0;
const float gravity = 0.5;
int dinoSkin = 0;

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
    Color color = (dinoSkin == 0) ? DARKGREEN :
                  (dinoSkin == 1) ? MAROON :
                  (dinoSkin == 2) ? BLUE :
                  (dinoSkin == 3) ? GOLD :
                                   DARKGREEN;

    // Corpul
    DrawRectangle(dinoX, dinoY, dinoSize, dinoSize, color);

    // Capul
    DrawRectangle(dinoX + dinoSize - 10, dinoY - 10, 15, 15, color);

    // Ochi
    DrawCircle(dinoX + dinoSize + 2, dinoY - 2, 3, WHITE);
    DrawCircle(dinoX + dinoSize + 2, dinoY - 2, 1, BLACK);

    // Picior 1
    DrawRectangle(dinoX + 5, dinoY + dinoSize, 5, 10, color);

    // Picior 2
    DrawRectangle(dinoX + 20, dinoY + dinoSize, 5, 10, color);

    // Coada
    DrawTriangle(
        (Vector2){ dinoX - 10, dinoY + 10 },
        (Vector2){ dinoX, dinoY + 5 },
        (Vector2){ dinoX, dinoY + 20 },
        color
    );
}

