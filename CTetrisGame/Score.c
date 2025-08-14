#include "Score.h"

int getScore(GameState* state)
{
	return state->gameScore;
}

void increaseScore(GameState* state, int new_score) {
	state->gameScore += new_score;
}