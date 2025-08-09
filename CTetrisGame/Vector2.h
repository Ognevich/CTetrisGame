#ifndef VECTOR2_H
#define VECTOR2_H
#include <stdbool.h>
#include <stdlib.h>
#include "Config.h"


typedef struct {
	int x;
	int y;
}Vector2;

Vector2* createVector2Array();
Vector2* findAllArrayObjects(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE], int* size);

int increaseVector2Array(Vector2** array, int* size);

void clearVector2Arr(Vector2** arr);

#endif 
