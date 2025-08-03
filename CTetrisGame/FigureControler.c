#include "FigureControler.h"

static Vector2 objCurrentPos;

void moveObject()
{
	if (objCurrentPos.y < MAP_HEIGHT - 2) { objCurrentPos.y++; }
}

void initObjectValues()
{
	objCurrentPos.x = START_POS_X;
	objCurrentPos.y = START_POS_Y;

}

int getCurrentPosX() { return objCurrentPos.x; }

int getCurrentPosY() { return objCurrentPos.y; }

const char (*getRandomFigure())[OBJECT_SIZE]
{
	int index = rand() % 7;
	return figures_arr[index];
}