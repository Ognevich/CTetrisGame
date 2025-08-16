#ifndef SCORE_H
#define SCORE_H
#include <Windows.h>
#include "GameState.h"
#include "FileControler.h"

int getScore(GameState * state);
void increaseScore(GameState* state, int new_score);
void showScoreStatistic();

#endif
