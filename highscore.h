#ifndef HIGHSCORE_H
#define HIGHSCORE_H

extern int highScore;  

void loadHighScore(); 
void saveHighScore();
void setHighScore(int newHighScore);  
int getHighScore(); 

#endif
