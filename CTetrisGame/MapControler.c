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
	int arrSize = 0;
	Vector2 *coordVector = findAllArrayObjects(state->tempFigureArr, &arrSize);

	for (int i = 0; i < arrSize; i++) {
		int currentY = coordVector[i].y + state->objCurrentPos.y;
		int currentX = coordVector[i].x + state->objCurrentPos.x - 1;
		if ((currentY == MAP_HEIGHT - 2) || (state->FilledObjectArr[currentY][currentX] == '0')) {
			clearVector2Arr(&coordVector);
			return 0;
		}
	}

	clearVector2Arr(&coordVector);
	return 1;
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

int checkLeftObjectCollision(GameState* state)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (state->tempFigureArr[i][j] != ' ') {
				int yPos = state->objCurrentPos.y + i-1;
				int xPos = state->objCurrentPos.x + j-1;

				if (state->FilledObjectArr[yPos][xPos-1] == '0') {
					return 1;
				}
			}
		}
	}
	return 0;
}

int checkRightObjectCollision(GameState* state)
{
	int maxCoordX = findMaxArrayXCoord(state->tempFigureArr) + getCurrentPosX(state) - 1;

	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (state->tempFigureArr[i][j] != ' ') {
				int yPos = state->objCurrentPos.y + i - 1;
				int xPos = state->objCurrentPos.x + j ;

				if (state->FilledObjectArr[yPos][xPos ] == '0') {
					return 1;
				}
			}
		}
	}

	return 0;
}
