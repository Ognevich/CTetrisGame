#include "MapControler.h"

char** mapArr = NULL;
size_t arraySize;


void createMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			addBorders(i, j);
		}
	}
}

void updateMap()
{
	clearMap();
	addObject(getCurrentPosY(), getCurrentPosX());
}

void addBorders(int x_coord, int y_coord)
{
	if (checkMapCollision(x_coord, y_coord) == 1) {
		mapArr[x_coord][y_coord] = '#';
	}
	else {
		mapArr[x_coord][y_coord] = ' ';
	}
}

void addObject(int y_coord, int x_coord)
{
	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {

			if (figureO[i][j] == '0') {
				int mapY = y_coord + i;
				int mapX = x_coord + j;

				coordArray[i][j].x = mapX;
				coordArray[i][j].y = mapY;

				mapArr[mapY][mapX] = figureO[i][j];
			}
		}
	}
}



void showMap()
{
	clearGameScreen();
	for (int i = 0; i < MAP_HEIGHT ; i++) {
		for (int j = 0; j < MAP_WIDTH ; j++) {
				printf("%c" ,mapArr[i][j]);
		}
		printf("\n");
	}

}

void clearMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (!checkMapCollision(i, j)) {
				mapArr[i][j] = ' ';
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

void initMapArray()
{
	char** temp = malloc(sizeof(char*) * MAP_HEIGHT);

	if (temp == NULL) {
		printf("memory init error");
		return;
	}

	for (int i = 0; i < MAP_HEIGHT; i++) {
		temp[i] = malloc(sizeof(char) * MAP_WIDTH);
		if (temp[i] == NULL) {
			printf("memory init error");
			for (int j = 0; j < i; j++) {
				free(temp[j]);
			}
			free(temp);

			return;
		}
	}

	mapArr = temp;
}

void freeMapArray(){

	if (mapArr == NULL) {
		return;
	}

	for (int i = 0; i < MAP_HEIGHT; i++) {
		free(mapArr[i]);
	}

	free(mapArr);
	mapArr = NULL;

}