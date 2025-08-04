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
};