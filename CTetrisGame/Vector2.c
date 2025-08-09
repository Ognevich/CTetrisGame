#include "Vector2.h"

Vector2* findAllArrayObjects(char currentFigure[OBJECT_SIZE][OBJECT_SIZE], int* size)
{
	*size = 0; 
	Vector2* coordArr = createVector2Array();

	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (currentFigure[i][j] == '0') {
				if (increaseVector2Array(&coordArr, size)) {
					coordArr[*size - 1].y = i;
					coordArr[*size - 1].x = j;
				}
			}
		}
	}

	return coordArr;
}


int increaseVector2Array(Vector2** array, int* size)
{
	int new_size = *size + 1;
	Vector2* temp = realloc(*array, new_size * sizeof(Vector2));
	if (temp == NULL) {
		return 0;
	}
	*array = temp;
	*size = new_size;
	return 1;
}

Vector2* createVector2Array()
{
	Vector2* arr = malloc(sizeof(Vector2));

	if (arr == NULL) {
		return 0;
	}

	return arr;
}

void clearVector2Arr(Vector2** arr)
{
	free(*arr);
	*arr = NULL;
}
