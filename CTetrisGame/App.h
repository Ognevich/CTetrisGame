#define _CRT_SECURE_NO_WARNINGS
#ifndef APP_H
#define APP_H
#include "stdio.h"
#include "MapControler.h"
#include "keyboardDetector.h"
#include "GameState.h"
#include <windows.h>

void Run(GameState* state);
void Init(GameState* state);
void Update(GameState* state);
void shutdown_app(GameState* state);

void playerActionHandler(GameState* state);

void handleLeftMovement(GameState* state);
void handleRightMovement(GameState* state);

#endif
