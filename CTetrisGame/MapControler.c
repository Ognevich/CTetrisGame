#include "MapControler.h"

void updateMap(GameState* state)
{
	clearMap(state);
	addObject(getCurrentPosY(state), getCurrentPosX(state),state);
}

void addObject(int y_coord, int x_coord, GameState* state)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {

			if (state->tempFigureArr[i][j] == '0') {
				int mapY = y_coord + i;
				int mapX = x_coord + j;

				state->mapArr[mapY][mapX] = state->tempFigureArr[i][j];
			}
		}
	}
}

void showMap(GameState* state)
{
	clearGameScreen();
	for (int i = 0; i < MAP_HEIGHT ; i++) {
		for (int j = 0; j < MAP_WIDTH ; j++) {
				printf("%c" ,state->mapArr[i][j]);
		}
		printf("\n");
	}
	printf("Score: %d\n", getScore(state));
	printf("ESC to exit\n");
}

void clearMap(GameState* state)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (!checkMapCollision(i, j)) {
				if (i > 0 && i <= OBJECT_MAP_HEIGHT && j > 0 && j <= OBJECT_MAP_WIDTH) {
					if (state->FilledObjectArr[i-1][j-1] != '0') {
						state->mapArr[i][j] = ' ';
					}
				}
			}
		}
	}
}

void ClearFullLine(GameState* state)
{
	
	for (int i = 0; i < OBJECT_MAP_HEIGHT; i++) {
		int objectCounter = 0;
		for (int j = 0; j < OBJECT_MAP_WIDTH; j++) {
			if (state->FilledObjectArr[i][j] == '0') {
				objectCounter++;
			}
			else { break; }
		}
		if (objectCounter == OBJECT_MAP_WIDTH) {
			playClearLineEffect(&state->sound);
			increaseScore(state, LINE_CLEAR_SCORE_INCRESE);
			deleteLineObject(state, i);
		}
	}
}
