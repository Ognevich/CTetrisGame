#ifndef UTILLS_H
#define UTILLS_H
#include <windows.h>
#include <stdio.h>
#include "Config.h"
#include "Vector2.h"

void clearGameScreen();
void wait(int sleepTime);
void setConsoleSize(int width, int height);

int findMaxArrayXCoord(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE]);

int* createIntArr(int size);
void increaseIntArr(int **arr, int *size);
void clearIntArr(int** arr);

#endif


