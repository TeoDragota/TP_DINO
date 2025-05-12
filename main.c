#include "raylib.h"
#include "dinozaur.h"
#include "obstacole.h"
#include "globals.h"
#include <stdio.h>

Texture2D bgAsh, bgAsteroid, bgCretacic, bgJurasic, bgTriasic, bgFinal, bgWinter;


int screenWidth = 800;
int screenHeight = 450;
int score = 0;
int highScore = 0;

void loadHighScore() {
    FILE *file = fopen("highscore.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }
}

void saveHighScore() {
    FILE *file = fopen("highscore.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", highScore);
        fclose(file);
    }
}

int main() {
    loadHighScore();

    InitWindow(screenWidth, screenHeight, "TP_DINO");
    bgAsh = LoadTexture("assets/ash.png");
    bgAsteroid = LoadTexture("assets/asteroid.jpeg");
    bgCretacic = LoadTexture("assets/cretacic.jpeg");
    bgFinal = LoadTexture("assets/final.png");
    bgJurasic = LoadTexture("assets/jurasic.jpeg");
    bgTriasic = LoadTexture("assets/triasic.jpeg");
    bgWinter = LoadTexture("assets/winter.jpeg");

    SetTargetFPS(60);

    initDino();
    initObstacole();

    bool gameOver = false;

    while (!WindowShouldClose()) {
        // UPDATE
        if (!gameOver) {
            updateDino();
            updateObstacole();

            // Coliziune cu oricare obstacol
            for (int i = 0; i < MAX_OBSTACOLE; i++) {
                Obstacol o = obstacole[i];
                if (dinoX + dinoSize > o.x && dinoX < o.x + o.width &&
                    dinoY + dinoSize > o.y && dinoY < o.y + o.height) {
                    gameOver = true;

                    if (score > highScore) {
                        highScore = score;
                        saveHighScore();
                    }
                    break;
                }
            }
        }

        // DRAW
        BeginDrawing();
        Texture2D currentBG = bgTriasic;

/**if (score >= 50) {
    currentBG = bgNowhere;
} else if (score >= 40) {
    currentBG = bgToxic;
} else if (score >= 30) {
    currentBG = bgMilitary;
} else if (score >= 20) {
    currentBG = bgNight;
} else if (score >= 10) {
    currentBG = bgComming;
}*/

if (score >=12)
    {currentBG = bgFinal;}
else if (score >= 10) {
    currentBG = bgWinter;
} else if (score >= 8) {
    currentBG = bgAsh;
} else if (score >= 6) {
    currentBG = bgAsteroid;
} else if (score >= 4) {
    currentBG = bgCretacic;
} else if (score >= 2) {
    currentBG = bgJurasic;
}

DrawTexturePro(
    currentBG,
    (Rectangle){ 0, 0, currentBG.width, currentBG.height },
    (Rectangle){ 0, 0, screenWidth, screenHeight },
    (Vector2){ 0, 0 },
    0.0f,
    WHITE
);



        drawDino();
        drawObstacole();

        if (gameOver) {
            const char* msg = "Game Over! Apasa R pentru a reintra!";
            int fontSize = 20;
            int textWidth = MeasureText(msg, fontSize);
            int posX = (screenWidth - textWidth) / 2;
            DrawText(msg, posX, 200, fontSize, DARKGRAY);

            if (IsKeyPressed(KEY_R)) {
                initDino();
                initObstacole();
                score = 0;
                gameOver = false;
            }
        } else {
            char scoreText[20];
            sprintf(scoreText, "Scor: %d", score);
            DrawText(scoreText, 10, 10, 20, DARKGRAY);

            char highScoreText[30];
            sprintf(highScoreText, "High Score: %d", highScore);
            DrawText(highScoreText, 10, 40, 20, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    UnloadTexture(bgFinal);
UnloadTexture(bgWinter);
UnloadTexture(bgAsh);
UnloadTexture(bgJurasic);
UnloadTexture(bgCretacic);
UnloadTexture(bgTriasic);
UnloadTexture(bgAsteroid);
    return 0;
}
