#ifndef MAP_DRAWER_H
#define MAP_DRAWER_H
#include <stdio.h>
#include <stdbool.h>
#include "FigureControler.h"
#include "Config.h"
#include "Utills.h"

void updateMap(GameState * state);
void showMap(GameState* state);
void clearMap(GameState* state);

void addObject(int x_coord, int y_coord, GameState* state);

int checkMapCollision(int height, int width);
int checkGroundCollision(GameState* state);
int checkLeftWallCollision(GameState* state);
int checkRightWallCollision(GameState* state);
int checkLeftObjectCollision(GameState* state);
int checkRightObjectCollision(GameState* state);

void ClearFullLine(GameState* state);
void deleteLineObject(int coordY);

#endif
