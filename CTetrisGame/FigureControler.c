#include "FigureControler.h"

void moveObjectDown(GameState* state)
{
	state->objCurrentPos.y++;
}

void moveObjectLeft(GameState* state)
{
	state->objCurrentPos.x--;
}

void moveObjectRight(GameState* state)
{
	state->objCurrentPos.x++;
}

void resetObject(GameState * state)
{
    state->objCurrentPos.x = START_POS_X;
    state->objCurrentPos.y = START_POS_Y;
    getRandomFigure(state);

}

void rotateObject(GameState* state)
{
    char** tempFigure = createDoubleCharArr();
    if (!tempFigure) return;

    for (int i = 0; i < OBJECT_SIZE; i++) {
        for (int j = 0; j < OBJECT_SIZE; j++) {
            tempFigure[j][OBJECT_SIZE - 1 - i] = state->tempFigureArr[i][j];
        }
    }

    if (isValidRotation(state, tempFigure)) {
        for (int i = 0; i < OBJECT_SIZE; i++) {
            for (int j = 0; j < OBJECT_SIZE; j++) {
                state->tempFigureArr[i][j] = tempFigure[i][j];
            }
        }
        playRotateEffect(&state->sound); 
    }

    clearDoubleCharArr(tempFigure);
}

int isValidRotation(GameState* state, char** rotatedFigure)
{
    int posX = state->objCurrentPos.x;
    int posY = state->objCurrentPos.y;

    for (int i = 0; i < OBJECT_SIZE; ++i) {
        for (int j = 0; j < OBJECT_SIZE; ++j) {
            if (rotatedFigure[i][j] == ' ') continue;

            int mapY = posY + i;
            int mapX = posX + j;

            if (mapY < 0 || mapY >= MAP_HEIGHT || mapX < 0 || mapX >= MAP_WIDTH)
                return 0;

            if (state->mapArr[mapY][mapX] == '#')
                return 0;

            int filledY = mapY - 1;
            int filledX = mapX - 1;

            if (filledY < 0 || filledY >= OBJECT_MAP_HEIGHT ||
                filledX < 0 || filledX >= OBJECT_MAP_WIDTH)
            {
                return 0;
            }

            if (state->FilledObjectArr[filledY][filledX] == '0')
                return 0;
        }
    }
    return 1;
}

char** createDoubleCharArr()
{
    char** tempFigure = malloc(OBJECT_SIZE * sizeof(char*));
    if (!tempFigure) return NULL;

    for (int i = 0; i < OBJECT_SIZE; i++) {
        tempFigure[i] = malloc(OBJECT_SIZE * sizeof(char));
        if (!tempFigure[i]) {
            for (int j = 0; j < i; j++)
                free(tempFigure[j]);
            free(tempFigure);
            return NULL;
        }

        for (int j = 0; j < OBJECT_SIZE; j++)
            tempFigure[i][j] = ' ';
    }

    return tempFigure;
}

void clearDoubleCharArr(char** rotateArr)
{
    for (int i = 0; i < OBJECT_SIZE; i++) {
        free(rotateArr[i]);
    }

    free(rotateArr);
}

int getCurrentPosX(GameState* state) { return state->objCurrentPos.x; }
int getCurrentPosY(GameState* state) { return state->objCurrentPos.y; }

void setCoordPosX(int coordX, GameState* state) { state->objCurrentPos.x = coordX; }

void setCoordPosY(int coordY, GameState* state) { state->objCurrentPos.y = coordY; }

void getRandomFigure(GameState* state)
{
	int index = rand() % 7;

	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			 state->tempFigureArr[i][j] = figures_arr[index][i][j];
		}
	}
}


void addValuesToFilledObjectArr(GameState* state)
{
    int posX = state->objCurrentPos.x;
    int posY = state->objCurrentPos.y;

    for (int i = 0; i < OBJECT_SIZE; i++) {
        for (int j = 0; j < OBJECT_SIZE; j++) {
            if (state->tempFigureArr[i][j] == '0') {
                int mapY = posY + i;
                int mapX = posX + j;

                state->FilledObjectArr[mapY - 1][mapX - 1] = '0';
            }
        }
    }
}

void resetFallSpeed(GameState* state)
{
    state->isFastFalling = 0;
}

void speedUpObject(GameState* state)
{
    state->isFastFalling = 1;
}
