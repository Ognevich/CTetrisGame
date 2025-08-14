#include "GameState.h"

void InitGameState(GameState* state)
{
	initMapArr(state);
	initFilledObjectArr(state);
	state->objCurrentPos.x = START_POS_X;
	state->objCurrentPos.y = START_POS_Y;
	state->isFastFalling = 0;
	state->fallDelay = NORMAL_FALL_DELAY;
	state->gameScore = 0;
}

void initMapArr(GameState* state)
{
	state->mapArr = malloc(MAP_HEIGHT * sizeof(char*));
	if (state->mapArr == NULL) {
		return;
	}
	for (int i = 0; i < MAP_HEIGHT; i++) {
		state->mapArr[i] = malloc(MAP_WIDTH * sizeof(char));
		if (state->mapArr[i] == NULL) {
			clearFailedState(&state->mapArr, i);
			return;
		}
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
				state->mapArr[i][j] = '#';
			}
			else {
				state->mapArr[i][j] = ' ';
			}
		}
	}
}

void initFilledObjectArr(GameState* state)
{

	state->FilledObjectArr = malloc(OBJECT_MAP_HEIGHT * sizeof(char*));
	if (state->FilledObjectArr == NULL) {
		return;
	}
	for (int i = 0; i < OBJECT_MAP_HEIGHT; i++) {
		state->FilledObjectArr[i] = malloc(OBJECT_MAP_WIDTH* sizeof(char));
		if (state->FilledObjectArr[i] == NULL) {
			clearFailedState(&state->FilledObjectArr, i);
			return;
		}
		for (int j = 0; j < OBJECT_MAP_WIDTH; j++) {
			state->FilledObjectArr[i][j] = ' ';
		}
	}
}

void clearFailedState(char*** array, int index)
{
	for (int k = 0; k < index; k++) {
		free((*array)[k]);
	}
	free(*array);
	*array = NULL;
}


void clearGameDoubleArray(char*** array, int height)
{
	for (int i = 0; i < height; i++) {
		free((*array)[i]);
	}
	free(*array);
	*array = NULL;
}

void clearGameState(GameState* state)
{
	clearGameDoubleArray(&state->mapArr, MAP_HEIGHT);
	clearGameDoubleArray(&state->FilledObjectArr, MAP_HEIGHT-2);
}

void deleteLineObject(GameState* state, int coordY)
{
	for (int i = coordY; i > 0; i--) {
		memcpy(state->FilledObjectArr[i], state->FilledObjectArr[i - 1], OBJECT_MAP_WIDTH);
	}

	for (int j = 0; j < OBJECT_MAP_WIDTH; j++) {
		state->FilledObjectArr[0][j] = ' ';
	}
}


