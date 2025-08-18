#include "keyboardDetector.h"
#include <windows.h>

keyPressed keyDetection() {
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 224) {
            ch = _getch();
            switch (ch) {
            case 75: return LEFT_ARR;
            case 77: return RIGHT_ARR;
            case 72: return UP_ARR;
            case 80: return DOWN_ARR;
            }
        }
        else if (ch == 27) {
            return ESC_BTN;
        }
    }
    return NONE;
}

int keyMenuDetection(const char **menuType, int menuSize, void (*func)(void))
{
    int menuOption = 0;
    int pressedKey = 0;

    while (1) {
        while (_kbhit()) _getch();
        
        system("cls");
        func();
        for (int i = 0; i < menuSize; i++) {
            
            if (i == menuOption) {
                printf("[*] %s\n", menuType[i]);
            }
            else {
                printf("[ ] %s\n", menuType[i]);
            }
        }

        pressedKey = getPressKey(&menuOption, menuSize);

        if (pressedKey == 1) {
            return menuOption;
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
            if (*menuOption < menuSize-1) (*menuOption)++;
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



