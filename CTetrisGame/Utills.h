#ifndef UTILLS_H
#define UTILLS_H
#include <windows.h>
#include <stdio.h>
#include "Config.h"

void clearGameScreen();
void wait(int sleepTime);


int findMaxArrayYCoord(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE]);
int findMaxArrayXCoord(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE]);

#endif


