/************************************************
* Title:      Assignment 1
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   13/09/2021
* Requisites: map.h, terminal.h, world.h, control.h
* Desc:       Maze Game
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "terminal.h"
#include "world.h"
#include "control.h"

/* function prototypes of the program */
void printMap(char ** arr, int rows, int cols, int arg);
int getPlayerCurrentPosX(char ** arr, int rows, int cols);
int getPlayerCurrentPosY(char ** arr, int rows, int cols);
void playerWin(char ** arr, int rows, int cols, int arg);

int main(int argc, char * argv[]) 
{   
    int rows;
    int cols;
    int amount;
    int **dataTable;
    int i;
    int visibility;
    char **mapLayout;
    visibility = 0;
    #ifdef DARK
        if ( (argc == 1) ||(atoi(argv[1])) < 0 || (argc > 2))
        {
            printf("Please Enter a Valid Argument - ./maze [visbility-distance]\n");
            return 0;
        }else if ((atoi(argv[1]) == 0))
        {
            visibility = 0;
        }else
        {
            visibility = atoi(argv[1]);
        }
    #endif
    /* getting the meta data from the map.c and storing in appropriate variables */
    getMetadata(&dataTable,&amount,&rows,&cols);
    /* making the map layout from the map.c data */
    mapLayout = (char **) malloc(sizeof(int *) * (rows));
    for ( i = 0; i < (rows); i++)
    {
        mapLayout[i] = NULL;
        mapLayout[i] = (char *) malloc(sizeof(int *) * (cols));
    }
    /* calling allocateMap function to allocate map data */
    allocateMap(mapLayout,rows,cols);
    /* calling allocateObjects function to allocate map object */
    allocateObjects(dataTable,mapLayout,amount,rows,cols,amount);
    /* calling controlPlayer function to control the player in the map */
    controlPlayer(mapLayout,rows,cols,visibility);
    /* freeing malloc data */
    for ( i = 0; i < (rows); i++)
    {
        free(mapLayout[i]);
        mapLayout[i] = NULL;
    }
    free(mapLayout);
    mapLayout = NULL;
    for ( i = 0; i < (rows); i++)
    {
        free(dataTable[i]);
    }
    free(dataTable);
    dataTable = NULL;
    return 0;
}

/* function to print the map to the screen */
void printMap(char ** arr, int rows, int cols, int arg)
{
    int r;
    int c;
    int playerX;
    int playerY;
    int vis;
    r=0;
    c=0;
    playerX=0;
    playerY=0;
    vis=0;
    playerX = getPlayerCurrentPosX(arr,rows,cols);
    playerY = getPlayerCurrentPosY(arr,rows,cols);
    /* printing the whole map (full visibility) */
    vis = arg;
    if (vis == 0)
    {
        for ( r = 0; r < rows; r++)
        {
            for ( c = 0; c < cols; c++)
            {
                printf("%c", arr[r][c]);
            }
            printf("\n");
        }
    }else if (vis>=(rows/2) && vis>=(cols/2))
    {
        for ( r = 0; r < rows; r++)
        {
            for ( c = 0; c < cols; c++)
            {
                printf("%c", arr[r][c]);
            }
            printf("\n");
        }
    }else {
    /* printing the user defined visibility map */
        /* checking if top border goes out of bounds */
        if ((playerX-vis<=0))
        {
            for ( r = 0; r <= (playerX+vis); r++)
            {
                for ( c = (playerY-vis); c <= (playerY+vis); c++)
                {
                    printf("%c", arr[r][c]);
                }
                printf("\n");
            }
        /* checking if bottom border goes out of bounds */
        }else if ((playerX+vis>=rows))
        {
            for ( r = playerX-vis; r < rows; r++)
            {
                for ( c = (playerY-vis); c <= (playerY+vis); c++)
                {
                    printf("%c", arr[r][c]);
                }
                printf("\n");
            }
        }else
        {
            /* if the borders doesn't go out of bounds for the argument */
            playerX = getPlayerCurrentPosX(arr,rows,cols);
            for ( r = (playerX)-(vis); r <= (playerX)+(vis); r++)
            {
                for ( c = ((playerY)-vis); c <= ((playerY)+vis); c++)
                {
                    printf("%c", arr[r][c]);
                }
                printf("\n");
            }
        }
    }
}

/* function to return the current player position in the map (row coordinate) */
int getPlayerCurrentPosX(char ** arr, int rows, int cols)
{
    int i;
    int j;
    int playerX;
    /* searching for the current row coordinate of the player position on the map */
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            if ((arr[i][j] == '^') || (arr[i][j] == 'v') || (arr[i][j] == '<') || (arr[i][j] == '>') )
            {
                playerX = i;
            }
            
        }
        
    }
    return playerX;
}

/* function to return the current player position in the map (column coordinate) */
int getPlayerCurrentPosY(char ** arr, int rows, int cols)
{
    int i;
    int j;
    int playerY;
    /* searching for the current column coordinate of the player position on the map */
    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            if ((arr[i][j] == '^') || (arr[i][j] == 'v') || (arr[i][j] == '<') || (arr[i][j] == '>') )
            {
                playerY = j;
            }
            
        }
        
    }
    return playerY;
}

/* function to display the player winning message */
void playerWin(char ** arr, int rows, int cols, int arg)
{
    int i;
    /* calling printMap function to print the map to the screen */
    printMap(arr,rows,cols,arg);
    printf("\n");
    printf("You Win!\n");
    printf("\n");
    /* freeing malloc data */
    for ( i = 0; i < (rows); i++)
    {
        free(arr[i]);
    }
    free(arr);
    exit(0);
}