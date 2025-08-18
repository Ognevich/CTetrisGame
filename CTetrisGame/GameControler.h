#define _CRT_SECURE_NO_WARNINGS
#ifndef GAME_CONTROLER_H
#define GAME_CONTROLER_H
#include <stdio.h>
#include <windows.h>
#include "MapControler.h"
#include "keyboardDetector.h"
#include "GameState.h"
#include "GameOverControler.h"
#include "Score.h"
#include "FileControler.h"
#include "SoundSystem.h"

void RunGame(GameState* state, GameStateType * gameStateType);
void Init(GameState* state);
void Update(GameState* state, GameStateType* gameStateType);
void shutdown_app(GameState* state);

void playerActionHandler(GameState* state, GameStateType* gameStateType);

void handleLeftMovement(GameState* state);
void handleRightMovement(GameState* state);

void SaveGameStatus(GameState* state, GameStateType* gameStateType);
#endif
