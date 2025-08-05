#ifndef FIGURE_CONTROLER_H
#define FIGURE_CONTROLER_H
#include "Figures.h"
#include <stdbool.h>
#include "Config.h"
#include "Utills.h"

typedef struct {
	int x;
	int y;
}Vector2;

extern Vector2 coordArray[OBJECT_SIZE][OBJECT_SIZE];


bool checkFigureCollision(int X_coord, int Y_coord);

void moveObjectDown();
void moveObjectLeft();
void moveObjectRight();
void moveVectorPos();

void rotateObject();

void setDafaultCoordPos();

int getCurrentPosX();
int getCurrentPosY();
const char (*getRandomFigure())[OBJECT_SIZE];

int getCoordVectorValueX(int coordX, int coordY);
int getCoordVectorValueY(int coordX, int coordY);

#endif
