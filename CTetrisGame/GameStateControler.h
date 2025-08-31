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
void handleGameColorSettings();
void handleGameSoundSettings();
void chooseGameSetting(int gameSettingsOption);

void handleGameMenu(GameStateType* gameStateType);
void handleGameStart(GameState* gameState, GameStateType* gameStateType);
void handleGameStatistic(GameStateType* gameStateType);
#endif
