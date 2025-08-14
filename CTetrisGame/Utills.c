#include "Utills.h"

void clearGameScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsole, cursorPosition);
}
void wait(int sleepTime) {
	Sleep(sleepTime);
}

void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int adjustedWidth = width + 7;
    int adjustedHeight = height;

    COORD bufferSize;
    bufferSize.X = adjustedWidth;
    bufferSize.Y = adjustedHeight;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = adjustedWidth - 1;
    windowSize.Bottom = adjustedHeight - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void setConsoleColor(int text, int background) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (background << 4) | text);
}

int findMaxArrayXCoord(char tempFigureArr[OBJECT_SIZE][OBJECT_SIZE])
{
	int coordX = 0;

	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (tempFigureArr[i][j] == '0') {
				if (j > coordX) {
					coordX = j;

				}
			}
		}
	}
	return coordX;
}

int findMinArraYCoord(char** objectFigure)
{
    int minValue = OBJECT_MAP_HEIGHT;
    for (int i = 0; i < OBJECT_MAP_HEIGHT; i++) {
        for (int j = 0; j < OBJECT_MAP_WIDTH; j++) {
            if (objectFigure[i][j] == '0' && minValue > i) {
                minValue = i;
            }
        }
    }
    return minValue;
}



int* createIntArr(int size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        return 0;
    }
    return arr;
}

void increaseIntArr(int** arr, int* size)
{
    int new_size = *size + 1;
    int* temp = realloc(*arr, new_size * sizeof(int));

    if (temp == NULL) {
        return;
    }

    *size = new_size;
    *arr = temp;

}

void clearIntArr(int** arr)
{
    
    free(*arr);
    *arr = NULL;
}

GameStateType convertIntToGameStateType(int* menuOption)
{
    switch (*menuOption)
    {
    case 0:
        return GAME_START;
    case 1:
        return GAME_STATISTIC;
    case 2:
        return GAME_SETTINGS;
    case 3:
        return GAME_EXIT;
    default:
        return GAME_MENU;
    }
}

void chooseGameColor(int settingsMenuOption)
{
    switch (settingsMenuOption)
    {
    case 0:
        setConsoleColor(11, 1);
        break;
    case 1:
        setConsoleColor(10, 0);
        break;
    case 2:
        setConsoleColor(14, 4);
        break;
    case 3:
        setConsoleColor(11, 5);
        break;
    case 4:
        setConsoleColor(7, 0);
        break;
    default:
        break;
    }
}
