#include "GameState.h"

void InitGameState(GameState* state)
{
	state->mapArr = malloc(MAP_HEIGHT * sizeof(char*));
	if (state->mapArr == NULL) {
		return;
	}
	for (int i = 0; i < MAP_HEIGHT; i++) {
		state->mapArr[i] = malloc(MAP_WIDTH * sizeof(char));
		if (state->mapArr[i] == NULL) {
			for (int k = 0; k < i; k++) {
				free(state->mapArr[k]);
			}
			free(state->mapArr);
			state->mapArr = NULL;
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

	state->objCurrentPos.x = START_POS_X;
	state->objCurrentPos.y = START_POS_Y;

}

void clearGameState(GameState* state)
{

	for (int i = 0; i < MAP_HEIGHT; i++) {
		free(state->mapArr[i]);
	}

	free(state->mapArr);
	state->mapArr = NULL;
}



