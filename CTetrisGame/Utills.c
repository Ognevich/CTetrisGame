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

void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int adjustedWidth = width+7;
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