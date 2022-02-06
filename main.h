#ifndef MAIN_H
#define MAIN_H

void printMap(char ** arr, int rows, int cols, int arg);
int getPlayerCurrentPosX(char ** arr, int rows, int cols);
int getPlayerCurrentPosY(char ** arr, int rows, int cols);
void playerWin(char ** arr, int rows, int cols, int arg);

#endif