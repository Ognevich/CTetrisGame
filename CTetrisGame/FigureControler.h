#ifndef FIGURE_CONTROLER_H
#define FIGURE_CONTROLER_H
#include "Figures.h"
#include "Config.h"

typedef struct {
	int x;
	int y;
}Vector2;

void moveObject();
void initObjectValues();

int getCurrentPosX();
int getCurrentPosY();
const char (*getRandomFigure())[OBJECT_SIZE];


#endif
