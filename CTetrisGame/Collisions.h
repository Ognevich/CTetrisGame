#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "GameState.h"
 
int checkMapCollision(int height, int width);
int checkGroundCollision(GameState* state, Vector2* coordVector, int* arrSize);

int checkLeftWallCollision(GameState* state);
int checkRightWallCollision(GameState* state);
int checkLeftObjectCollision(GameState* state);
int checkRightObjectCollision(GameState* state);


#endif
