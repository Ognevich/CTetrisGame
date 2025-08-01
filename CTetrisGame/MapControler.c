#include "MapControler.h"

char* Map = NULL;

void drawMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (checkMapCollision(i, j) == 1) {
				printf("#");
			}
		}
		printf("\n");
	}


}

int checkMapCollision(int height, int width)
{
	
	if ((height == 0 || height == MAP_HEIGHT) || (width == 0 || width == MAP_WIDTH)) {
	
		return 1;
	};

	return 0;
}
