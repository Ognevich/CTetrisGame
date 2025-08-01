#ifndef MAP_DRAWER_H
#define MAP_DRAWER_H
#include <stdio.h>
#include "Utills.h"

#define MAP_HEIGHT 20
#define MAP_WIDTH 40

extern char** mapArr;
extern size_t arraySize;

void createMap();
void showMap();

int checkMapCollision(int height, int width);

void initMapArray();
void freeMapArray();
#endif
