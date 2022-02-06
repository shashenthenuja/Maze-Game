#include<stdio.h>
#include <stdlib.h>
#include<termios.h>
#include"terminal.h"
#include "main.h"

int getPlayerCurrentPosX(char ** arr, int rows, int cols);
int getPlayerCurrentPosY(char ** arr, int rows, int cols);
void playerWin(char ** arr, int rows, int cols, int arg);
void printMap(char ** arr, int rows, int cols, int arg);

/* function to control the player inside the map */
void controlPlayer(char ** arr, int rows, int cols, int arg)
{
    int playerX;
    int playerY;
    int cont;
    char ch;
    printMap(arr,rows,cols,arg);
    playerX = getPlayerCurrentPosX(arr,rows,cols);
    playerY = getPlayerCurrentPosY(arr,rows,cols);
    cont = 1;
    /* do while loop to continue the player movement until the player wins */
    do {
        /* taking input from the user */
        disableBuffer();
        scanf(" %c", &ch);
        enableBuffer();
        /* switch function to get the valid control input from the user */
        switch (ch)
        {
        case 'w':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position */
            if ((playerX > 1) && (arr[playerX-1][playerY]==' ' || arr[playerX-1][playerY]=='x'))
            {
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                /*  checking to see if the next path contains the goal */
                if (arr[playerX-1][playerY]=='x')
                {
                    arr[playerX-1][playerY] = '^';
                    arr[playerX][playerY] = ' ';
                    playerWin(arr,rows,cols,arg);
                }else {
                /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX-1][playerY] = '^';
                    printMap(arr,rows,cols,arg);
                }
                break;
            }else {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = '^';
                printMap(arr,rows,cols,arg);
                break;
            }
        case 'a':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position */
            if ((playerY > 1) && ((arr[playerX][playerY-1]==' ') || arr[playerX][playerY-1]=='x'))
            {
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                /*  checking to see if the next path contains the goal */
                if (arr[playerX][playerY-1]=='x')
                {
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY-1] = '<';
                    playerWin(arr,rows,cols,arg);
                }else {
                /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY-1] = '<';
                    printMap(arr,rows,cols,arg);
                }
                break;
            }else {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = '<';
                printMap(arr,rows,cols,arg);
                break;
            }
            
        case 's':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position */
            if ((playerX < rows-2) && ((arr[playerX+1][playerY]==' ') || arr[playerX+1][playerY]=='x'))
            {
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                /*  checking to see if the next path contains the goal */
                if (arr[playerX+1][playerY]=='x')
                {
                    arr[playerX][playerY] = ' ';
                    arr[playerX+1][playerY] = 'v';
                    playerWin(arr,rows,cols,arg);
                }else {
                /* continuing the path if there are no obstructions or goal */
                    arr[playerX][playerY] = ' ';
                    arr[playerX+1][playerY] = 'v';
                    printMap(arr,rows,cols,arg);
                }
                break;
            }else {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = 'v';
                printMap(arr,rows,cols,arg);
                break;
            }
            
        case 'd':
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            playerY = getPlayerCurrentPosY(arr,rows,cols);
            /* checking if the player is inside the border and on an empty path or if the player is on the goal position */
            if ((playerY < cols-2) && (arr[playerX][playerY+1]==' ' || arr[playerX][playerY+1]=='x'))
            {
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                /*  checking to see if the next path contains the goal */
                if (arr[playerX][playerY+1]=='x')
                {
                    arr[playerX][playerY] = ' ';
                    arr[playerX][playerY+1] = '>';
                    playerWin(arr,rows,cols,arg);
                } else {
                /* continuing the path if there are no obstructions or goal */
                arr[playerX][playerY] = ' ';
                arr[playerX][playerY+1] = '>';
                printMap(arr,rows,cols,arg);
                }
                break;
            } else {
                /* collision detection & print position when the player is near an obstruction */
                system("clear");
                playerX = getPlayerCurrentPosX(arr,rows,cols);
                playerY = getPlayerCurrentPosY(arr,rows,cols);
                arr[playerX][playerY] = '>';
                printMap(arr,rows,cols,arg);
                break;
            }
        default:
            break;
        }
    } while(cont==1);
}