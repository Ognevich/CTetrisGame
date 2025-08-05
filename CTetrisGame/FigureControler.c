#include "FigureControler.h"

static Vector2 objCurrentPos;
Vector2 coordArray[OBJECT_SIZE][OBJECT_SIZE];
char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE];

void moveObjectDown()
{
	objCurrentPos.y++;
}

void moveObjectLeft()
{
	objCurrentPos.x--;
}

void moveObjectRight()
{
	objCurrentPos.x++;
}

void moveVectorPos()
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			coordArray[i][j].x = j + objCurrentPos.x;
			coordArray[i][j].y = i + objCurrentPos.y;
		}
	}
}

void resetObject()
{
	setDafaultCoordPos();
	getRandomFigure();
}

void rotateObject()
{
	int** tempFigure = malloc(OBJECT_SIZE * sizeof(int*));
	if (tempFigure == NULL) {
		return;
	}

	for (int i = 0; i < OBJECT_SIZE; i++) {
		tempFigure[i] = malloc(OBJECT_SIZE * sizeof(int));
		if (tempFigure[i] == NULL) {
			for (int j = 0; j < i; j++) {
				free(tempFigure[j]);
			}
			free(tempFigure);
			return;
		}
	}
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			tempFigure[j][OBJECT_SIZE - 1 - i] = tempFigureArr[i][j];
		}
	}
	setNewRotateObject(tempFigure);
}

void setNewRotateObject(char** rotateArr)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			tempFigureArr[i][j] = rotateArr[i][j];
		}
	}

	clearDobuleCharArr(rotateArr);
}

void clearDobuleCharArr(char** rotateArr)
{

	for (int i = 0; i < OBJECT_SIZE; i++) {
		free(rotateArr[i]);
	}

	free(rotateArr);
}



void setDafaultCoordPos()
{
	objCurrentPos.x = START_POS_X;
	objCurrentPos.y = START_POS_Y;
}


bool checkFigureCollision(int X_coord, int Y_coord)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (X_coord == getCoordVectorValueX(i,j) && Y_coord == getCoordVectorValueY(i,j)) {
				return true;
				break;
			}
		}
	}
	return false;
}

int getCurrentPosX() { return objCurrentPos.x; }
int getCurrentPosY() { return objCurrentPos.y; }

void setCoordPosX(int coordX) { objCurrentPos.x = coordX; }

void setCoordPosY(int coordY) { objCurrentPos.y = coordY; }

void getRandomFigure()
{
	int index = rand() % 7;

	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			 tempFigureArr[i][j] = figures_arr[index][i][j];
		}
	}
}

int getCoordVectorValueX(int coordX, int coordY) { return coordArray[coordX][coordY].x; }
int getCoordVectorValueY(int coordX, int coordY) { return coordArray[coordX][coordY].y; }

int checkGroundCollision()
{
	if (objCurrentPos.y == MAP_HEIGHT - 3) {
		return 1;
	}
	return 0;
}

