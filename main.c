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

bool gameStarted = false;


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

    //alegem skin
        int availableSkins = 1;
    if (highScore >= 30) availableSkins = 4;
    else if (highScore >= 20) availableSkins = 3;
    else if (highScore >= 10) availableSkins = 2;

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
        BeginDrawing();

        if (!gameStarted) {
            ClearBackground(BEIGE);

            const char* title = "Calatorie in timp";
            int fontSize = 50;
            int titleWidth = MeasureText(title, fontSize);
            DrawText(title, (screenWidth - titleWidth)/2, 100, fontSize, DARKGREEN);

            const char* startText = "Apasa SPACE pentru a incepe!";
            int startWidth = MeasureText(startText, 20);
            DrawText(startText, (screenWidth - startWidth)/2, 250, 20, DARKGRAY);

            if (IsKeyPressed(KEY_SPACE)) {
                gameStarted = true;
            }
            const char* skinMsg = "Alege skin-ul:";
            int skinMsgW = MeasureText(skinMsg, 20);
            DrawText(skinMsg, (screenWidth - skinMsgW) / 2, 300, 20, DARKGRAY);

            // Alege cu tastele
            if (IsKeyPressed(KEY_RIGHT)) dinoSkin++;
            if (IsKeyPressed(KEY_LEFT))  dinoSkin--;
            if (dinoSkin < 0) dinoSkin = availableSkins - 1;
            if (dinoSkin >= availableSkins) dinoSkin = 0;

            // Eticheta skinului curent
            Color skinColor = (dinoSkin == 0) ? DARKGREEN :
                            (dinoSkin == 1) ? MAROON :
                            (dinoSkin == 2) ? BLUE :
                            (dinoSkin == 3) ? GOLD :
                                                DARKGRAY;

            const char* skinName = (dinoSkin == 0) ? "Verde" :
                                (dinoSkin == 1) ? "Rosu" :
                                (dinoSkin == 2) ? "Albastru" :
                                (dinoSkin == 3) ? "Auriu" :
                                                    "???";

            int nameW = MeasureText(skinName, 30);
            DrawText(skinName, (screenWidth - nameW) / 2, 340, 30, skinColor);

            EndDrawing(); 
            continue;     // nu mai desenăm nimic altceva
        }

        // UPDATE (numai dacă jocul a început și nu e game over)
        if (!gameOver) {
            updateDino();
            updateObstacole();

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

        // ALEGE FUNDALUL
        Texture2D currentBG = bgTriasic;

        if (score >= 12) {
            currentBG = bgFinal;
        } else if (score >= 10) {
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
            DrawText(msg, posX, 200, fontSize, RAYWHITE);

            if (IsKeyPressed(KEY_R)) {
                initDino();
                initObstacole();
                score = 0;
                gameOver = false;
            }
        } else {
            char scoreText[20];
            sprintf(scoreText, "Scor: %d", score);
            DrawText(scoreText, 10, 10, 20, RAYWHITE);

            char highScoreText[30];
            sprintf(highScoreText, "High Score: %d", highScore);
            DrawText(highScoreText, 10, 40, 20, RAYWHITE);
        }

        EndDrawing();
    }

    // RESURSE & ÎNCHIDERE
    UnloadTexture(bgFinal);
    UnloadTexture(bgWinter);
    UnloadTexture(bgAsh);
    UnloadTexture(bgJurasic);
    UnloadTexture(bgCretacic);
    UnloadTexture(bgTriasic);
    UnloadTexture(bgAsteroid);

    CloseWindow();
    return 0;
}
