#ifndef MAP_DRAWER_H
#define MAP_DRAWER_H
#include <stdio.h>
#include <stdbool.h>
#include "FigureControler.h"
#include "Config.h"
#include "Utills.h"


extern char** mapArr;
extern size_t arraySize;

void createMap();
void updateMap();
void showMap();
void clearMap();

void addBorders(int x_coord, int y_coord);
void addObject(int x_coord, int y_coord);

int checkMapCollision(int height, int width);

void initMapArray();
void freeMapArray();
#endif
