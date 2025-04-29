#include "raylib.h"
#include "dinozaur.h"
#include "obstacole.h"
#include "highscore.h"  
#include <stdio.h>

int screenWidth = 800;
int screenHeight = 450;

int score = 0;  
Texture2D background;  


bool obstacle1Passed = false;  
bool obstacle2Passed = false;  

int main() {
    InitWindow(screenWidth, screenHeight, "TP_DINO");
    SetTargetFPS(60);


    background = LoadTexture("background.png");  
    loadHighScore();  
    initDino();  
    initObstacol1();  
    initObstacol2();  

    bool gameOver = false; 

    while (!WindowShouldClose()) {  
        // UPDATE
        if (!gameOver) {
            updateDino(); 
            updateObstacol1();  
            updateObstacol2();  


            if (dinoX + dinoSize > obstacle1X && dinoX < obstacle1X + obstacle1Width && 
                !obstacle1Passed) {
                score++;  
                obstacle1Passed = true;  
                printf("Scorul a crescut la: %d\n", score);  
            }


            if (dinoX + dinoSize > obstacle2X && dinoX < obstacle2X + obstacle2Radius * 2 &&
                !obstacle2Passed) {
                score++;  
                obstacle2Passed = true;  
                printf("Scorul a crescut la: %d\n", score);  
            }

            if (checkCollisionWithDino1(dinoX, dinoY, dinoSize)) {
                gameOver = true;  /
            }


            if (checkCollisionWithDino2(dinoX, dinoY, dinoSize)) {
                gameOver = true;  //
            }

            if (obstacle1X + obstacle1Width < 0) {
                obstacle1Passed = false;  
                initObstacol1();  
            }

            if (obstacle2X + obstacle2Radius * 2 < 0) {
                obstacle2Passed = false;  
                initObstacol2();  
            }
        }

        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        
        Vector2 scale = { (float)screenWidth / background.width, (float)screenHeight / background.height };
        DrawTextureEx(background, (Vector2){ 0, 0 }, 0.0f, scale.x, WHITE);  

        drawDino();  
        drawObstacol1();  
        drawObstacol2();  


        char scoreText[20];
        sprintf(scoreText, "Scor: %d", score); 
        DrawText(scoreText, 10, 10, 20, DARKGRAY);  


        char highScoreText[50];
        sprintf(highScoreText, "High Score: %d", getHighScore());  
        DrawText(highScoreText, 10, 40, 20, DARKGRAY);  

        if (gameOver) {

            int textWidth = MeasureText("Game Over! Apasa R pentru a reintra!", 20);
            int textHeight = 20;  

            int posX = (screenWidth - textWidth) / 2;
            int posY = (screenHeight - textHeight) / 2;


            char gameOverText[256];  
            sprintf(gameOverText, "Game Over! Apasa R pentru a reintra! ");
            DrawText(gameOverText, posX, posY, 20, DARKGRAY);


            if (score > getHighScore()) {
                setHighScore(score);  
                saveHighScore();      
            }


            if (IsKeyPressed(KEY_R)) {

                initDino();
                initObstacol1();
                initObstacol2();
                score = 0;  
                gameOver = false;
                obstacle1Passed = false;  
                obstacle2Passed = false;  
            }
        }

        EndDrawing();  
    }

    UnloadTexture(background);  // Eliberăm memoria pentru fundal
    CloseWindow();  // Închide fereastra

    return 0;
}
