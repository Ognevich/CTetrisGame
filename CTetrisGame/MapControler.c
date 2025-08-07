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

}

void clearMap(GameState* state)
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (!checkMapCollision(i, j)) {
				if (i > 0 && i < MAP_HEIGHT - 1 && j > 0 && j < MAP_WIDTH - 1) {
					if (state->FilledObjectArr[i - 1][j - 1] != '0') {
						state->mapArr[i][j] = ' ';
					}
				}
			}
		}
	}
}

int checkMapCollision(int height, int width)
{
	if ((height == 0 || height == MAP_HEIGHT-1) || (width == 0 || width == MAP_WIDTH-1)) {
			return 1;
	}
	return 0;
}

int checkGroundCollision(GameState* state)
{
	int coordY = findMaxArrayYCoord(state->tempFigureArr);

	int xPos = getCurrentPosX(state);
	int yPos = getCurrentPosY(state) + coordY;

	if ((yPos + 2 == MAP_HEIGHT)||state->FilledObjectArr[yPos][xPos] == '0') {
		return 1;
	}
	return 0;
}

int checkLeftWallCollision(GameState* state)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (state->tempFigureArr[i][j] != ' ') {
				int mapY = state->objCurrentPos.y + i;
				int mapX = state->objCurrentPos.x + j;

				if (mapX - 1 < 0) 
					return 1;

				if (state->mapArr[mapY][mapX - 1] == '#')  
					return 1;
			}
		}
	}
	return 0;
}

int checkRightWallCollision(GameState* state)
{
	int yPos = getCurrentPosY(state);
	int maxCoordX = findMaxArrayXCoord(state->tempFigureArr) + getCurrentPosX(state);

	if (state->mapArr[yPos][maxCoordX + 1] == '#') {
		return 1; 
	}
	return 0;
}