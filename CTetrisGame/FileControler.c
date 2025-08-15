#include "FileControler.h"

void saveScoreToFile(int scoreToSave)
{
	FILE* file = fopen(scoreFilePath, "a");
	fprintf(file, "%d\n", scoreToSave);
	fclose(file);
}

int *getAllDataFromFile(int * outSize)
{
	int size = 1;
	int* arr = createIntArr(1);

	FILE* file = fopen(scoreFilePath, "r");

	while (fscanf(file, "%d\n", &arr[size-1]) == 1)
		increaseIntArr(&arr, &size);

	fclose(file);
	*outSize = size;

	return arr;
}


