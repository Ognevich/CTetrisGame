#ifndef GAME_OVER_CONTROLER_H
#define GAME_OVER_CONTROLER_H
#include <stdio.h>
#include <conio.h>
#include "GameState.h"
#include "Config.h"
#include "Utills.h"
#include "FileControler.h"

void GameOverMessage(int currentScore);
int isGameOver(GameState* state);

#endif
