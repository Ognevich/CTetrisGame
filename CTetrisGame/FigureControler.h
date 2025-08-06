#ifndef FIGURE_CONTROLER_H
#define FIGURE_CONTROLER_H
#include "Figures.h"
#include "Config.h"
#include "Utills.h"
#include "GameState.h"

void moveObjectDown(GameState * state);
void moveObjectLeft(GameState* state);
void moveObjectRight(GameState* state);
void moveVectorPos(GameState* state);

void resetObject(GameState* state);
void rotateObject(GameState* state);
int isValidRotation(GameState* state, char**rotatedFigure);

char** createDoubleCharArr();
void clearDoubleCharArr(char** rotateArr);


int getCurrentPosX(GameState* state);
int getCurrentPosY(GameState* state);
void setCoordPosX(int coordX, GameState* state);
void setCoordPosY(int coordY, GameState* state);

void getRandomFigure(GameState* state);

int getCoordVectorValueX(int coordX, int coordY, GameState* state);
int getCoordVectorValueY(int coordX, int coordY, GameState* state);

#endif
