#include "keyboardDetector.h"
#include <windows.h>

keyPressed keyDetection()
{
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)  return LEFT_ARR;
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) return RIGHT_ARR;
    if (GetAsyncKeyState(VK_UP) & 0x8000)    return UP_ARR;
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)  return DOWN_ARR;

    return NONE;
}

void keyMenuDetection(GameStateType* gameStateType)
{
    int menuOption = 0;
    int pressedKey = 0;

    while (1) {
        while (_kbhit()) _getch();
        
        system("cls");
        for (int i = 0; i < MAIN_MENU_SIZE; i++) {
            
            if (i == menuOption) {
                printf("[*] %s\n", mainMenuArr[i]);
            }
            else {
                printf("[ ] %s\n", mainMenuArr[i]);
            }
        }

        pressedKey = getPressKey(&menuOption, MAIN_MENU_SIZE);

        if (pressedKey == 1) {
            *gameStateType = convertIntToGameStateType(&menuOption);
            return;
        }

    }
}

int getPressKey(int* menuOption, int menuSize)
{
    int ch = _getch();

    if (ch == 224) {
        ch = _getch();
        switch (ch)
        {
        case 72:
            if (*menuOption > 0) (*menuOption)--;
            break;
        case 80:
            if (*menuOption < MAIN_MENU_SIZE-1) (*menuOption)++;
            break;
        default:
            break;
        }
    }
    else if (ch == 13) {
        return 1;
    }
    return 0;

}



