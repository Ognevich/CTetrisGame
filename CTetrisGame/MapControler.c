#include "MapControler.h"

char** mapArr = NULL;
size_t arraySize;

int currentPosX = 1;
int currentPosY = MAP_WIDTH / 2;

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
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (checkMapCollision(i,j) == 0) {
				mapArr[i][j] == ' ';
			}
			addObject(i,j);
		}
	}
}

void showMap()
{
	clearScreen();
	for (int i = 0; i < MAP_HEIGHT ; i++) {
		for (int j = 0; j < MAP_WIDTH ; j++) {
				printf("%c" ,mapArr[i][j]);
		}
		printf("\n");
	}

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


void addObject(int x_coord, int y_coord)
{
	if (x_coord == currentPosX && y_coord == currentPosY) {
		mapArr[x_coord][y_coord] = '0';
	}
}

void moveObject()
{
	if (currentPosX < MAP_HEIGHT - 2) 
		currentPosX++;
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