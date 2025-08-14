#ifndef GAME_STATE_TYPE_H
#define GAME_STATE_TYPE_H
#include "GameControler.h"
#include "GameState.h"
#include "GameStateType.h"
#include "keyboardDetector.h"
#include "MenuArr.h"

void runProgram(GameStateType * gameStateType, GameState * state);
void handleCurrentGameState(GameStateType * gameStateType, GameState* state);

void handleGameSettings(GameStateType* gameStateType);
#endif
