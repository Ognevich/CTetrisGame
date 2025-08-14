#define _CRT_SECURE_NO_WARNINGS
#ifndef GAME_CONTROLER_H
#define GAME_CONTROLER_H
#include "stdio.h"
#include "MapControler.h"
#include "keyboardDetector.h"
#include "GameState.h"
#include "GameOverControler.h"
#include <windows.h>

void RunGame(GameState* state, GameStateType * gameStateType);
void Init(GameState* state);
void Update(GameState* state, GameStateType* gameStateType);
void shutdown_app(GameState* state);

void playerActionHandler(GameState* state);

void handleLeftMovement(GameState* state);
void handleRightMovement(GameState* state);

#endif
