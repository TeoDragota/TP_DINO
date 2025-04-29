#include "highscore.h"
#include <stdio.h>

int highScore = 0;  

void loadHighScore() {
    FILE *file = fopen("highscore.dat", "r");
    if (file != NULL) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }
}

void saveHighScore() {
    FILE *file = fopen("highscore.dat", "w");
    if (file != NULL) {
        fprintf(file, "%d", highScore);
        fclose(file);
    }
}

void setHighScore(int newHighScore) {
    highScore = newHighScore;
}

int getHighScore() {
    return highScore;
}

