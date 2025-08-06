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

int findMaxArrayYCoord(char currentFigure[OBJECT_SIZE][OBJECT_SIZE])
{
	int coordY = 0;

	for (int i = 0; i < OBJECT_SIZE; i++) {
		for (int j = 0; j < OBJECT_SIZE; j++) {
			if (currentFigure[i][j] == '0') {
				if (i > coordY) {
					coordY = i;
				}
			}
		}
	}
	return coordY;
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
