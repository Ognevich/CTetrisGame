#include "Collisions.h"

int checkMapCollision(int height, int width)
{
	if ((height == 0 || height == MAP_HEIGHT - 1) || (width == 0 || width == MAP_WIDTH - 1)) {
		return 1;
	}
	return 0;
}



int checkGroundCollision(GameState* state, Vector2* coordVector, int* arrSize)
{

	for (int i = 0; i < *arrSize; i++) {
		int currentY = coordVector[i].y + state->objCurrentPos.y;
		int currentX = coordVector[i].x + state->objCurrentPos.x - 1;
		if ((currentY == MAP_HEIGHT - 2) || (state->FilledObjectArr[currentY][currentX] == '0')) {
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
				int yPos = state->objCurrentPos.y + i - 1;
				int xPos = state->objCurrentPos.x + j - 1;

				if (state->FilledObjectArr[yPos][xPos - 1] == '0') {
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
				int xPos = state->objCurrentPos.x + j;

				if (state->FilledObjectArr[yPos][xPos] == '0') {
					return 1;
				}
			}
		}
	}

	return 0;
}
