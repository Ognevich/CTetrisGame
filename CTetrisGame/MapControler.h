#ifndef MAP_DRAWER_H
#define MAP_DRAWER_H
#include <stdio.h>
#include "Utills.h"


#define MAP_HEIGHT 10
#define MAP_WIDTH 20


extern char* Map;

void drawMap();
int checkMapCollision(int height, int width);

#endif
