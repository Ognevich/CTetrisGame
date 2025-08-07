#include "GameState.h"

void InitGameState(GameState* state)
{
	initMapArr(state);
	initFilledObjectArr(state);
	state->objCurrentPos.x = START_POS_X;
	state->objCurrentPos.y = START_POS_Y;

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
	const int filledObjectHeight = MAP_HEIGHT - 2;
	const int filledObjectWidth = MAP_WIDTH - 2;

	state->FilledObjectArr = malloc(filledObjectHeight * sizeof(char*));
	if (state->FilledObjectArr == NULL) {
		return;
	}
	for (int i = 0; i < filledObjectHeight; i++) {
		state->FilledObjectArr[i] = malloc(filledObjectWidth * sizeof(char));
		if (state->FilledObjectArr[i] == NULL) {
			clearFailedState(&state->FilledObjectArr, i);
			return;
		}
		for (int j = 0; j < filledObjectWidth; j++) {
			state->FilledObjectArr[i][j] = ' ';
		}
	}
}

void clearFailedState(char *** array, int index)
{
	for (int k = 0; k < index; k++) {
		free(*array[k]);
	}
	free(*array);
	*array = NULL;
}

void clearGameDoubleArray(char*** array, int height)
{
	for (int i = 0; i < height; i++) {
		free(*array[i]);
	}

	free(*array);
	*array = NULL;
}

void clearGameState(GameState* state)
{
	clearGameDoubleArray(&state->mapArr, MAP_HEIGHT);
	clearGameDoubleArray(&state->FilledObjectArr, MAP_HEIGHT-2);
}



