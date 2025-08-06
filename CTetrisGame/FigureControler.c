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

void moveVectorPos(GameState* state)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			state->coordArray[i][j].x = j + state->objCurrentPos.x;
			state->coordArray[i][j].y = i + state->objCurrentPos.y;
		}
	}
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
    }

    clearDoubleCharArr(tempFigure);
}

int isValidRotation(GameState* state, char** rotatedFigure)
{
    int posX = state->objCurrentPos.x;
    int posY = state->objCurrentPos.y;

    for (int i = 0; i < OBJECT_SIZE; i++) {
        for (int j = 0; j < OBJECT_SIZE; j++) {
            if (rotatedFigure[i][j] != ' ') {
                int mapY = posY + i;
                int mapX = posX + j;

                if (mapY < 0 || mapY >= MAP_HEIGHT || mapX < 0 || mapX >= MAP_WIDTH)
                    return 0;
                if (state->mapArr[mapY][mapX] == '#')
                    return 0;
            }
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

int getCoordVectorValueX(int coordX, int coordY, GameState* state) { return state->coordArray[coordX][coordY].x; }
int getCoordVectorValueY(int coordX, int coordY, GameState* state) { return state->coordArray[coordX][coordY].y; }
