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
extern char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE];

bool checkFigureCollision(int X_coord, int Y_coord);

void moveObjectDown();
void moveObjectLeft();
void moveObjectRight();
void moveVectorPos();

void resetObject();
void rotateObject();

void setNewRotateObject(char** rotateArr);
void clearDobuleCharArr(char** rotateArr);

void setDafaultCoordPos();

int getCurrentPosX();
int getCurrentPosY();
void setCoordPosX(int coordX);
void setCoordPosY(int coordY);

void getRandomFigure();

int getCoordVectorValueX(int coordX, int coordY);
int getCoordVectorValueY(int coordX, int coordY);


int findMaxArrayXCoord(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE]);
#endif
