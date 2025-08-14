#ifndef UTILLS_H
#define UTILLS_H
#include <windows.h>
#include <stdio.h>
#include "Config.h"
#include "Vector2.h"
#include "GameStateType.h"

void clearGameScreen();
void wait(int sleepTime);
void setConsoleSize(int width, int height);
void setConsoleColor(int textColor, int backgroundColor);

int findMaxArrayXCoord(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE]);

int* createIntArr(int size);
void increaseIntArr(int **arr, int *size);
void clearIntArr(int** arr);

GameStateType convertIntToGameStateType(int* menuOption);
void chooseGameColor(int settingsMenuOption);

#endif


