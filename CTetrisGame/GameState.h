#ifndef GAME_STATE_H
#define GAME_STATE_H
#include <stdlib.h>
#include "Config.h"
#include "Vector2.h"


typedef struct {
    char** mapArr;
    Vector2 objCurrentPos;
    char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE];
    Vector2 coordArray[OBJECT_SIZE][OBJECT_SIZE];
}GameState;

void InitGameState(GameState* state);
void clearGameState(GameState* state);

#endif 
