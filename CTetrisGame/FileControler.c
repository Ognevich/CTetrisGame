#include "FileControler.h"

void saveScoreToFile(int scoreToSave)
{
	FILE* file = fopen(scoreFilePath, "a");
	fprintf(file, "%d\n", scoreToSave);
	fclose(file);
}

int* getAllDataFromFile(int* outSize)
{
    int size = 0; 
    int* arr = NULL;
    int value;

    FILE* file = fopen(scoreFilePath, "r");
    if (!file) return NULL;

    while (fscanf(file, "%d", &value) == 1) {
        if (!increaseIntArr(&arr, &size)) {
            fclose(file);
            return NULL;
        }
        arr[size - 1] = value; 
    }

    fclose(file);
    *outSize = size;
    return arr;
}

int* readTopFiveScores()
{
    int size = 0;
    int* arr = getAllDataFromFile(&size);
    bubbleSort(&arr, size);

    int* new_arr = malloc(sizeof(int) * 5);

    if (new_arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < 5; i++) {
        new_arr[i] = arr[i];
    }

    clearIntArr(&arr);

    return new_arr;
}


