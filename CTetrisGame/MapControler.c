#include "MapControler.h"

char** mapArr = NULL;
size_t arraySize;

void createMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (checkMapCollision(i, j) == 1) {
				mapArr[i][j] = '#';
			}
			else {
				mapArr[i][j] = ' ';
			}
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



int checkMapCollision(int height, int width)
{
	if ((height == 0 || height == MAP_HEIGHT-1) || (width == 0 || width == MAP_WIDTH-1)) {
			return 1;
	};
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