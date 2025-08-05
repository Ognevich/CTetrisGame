#include "keyboardDetector.h"

keyPressed keyDetection()
{
    if (_kbhit()) { 
        int ch = _getch();

        if (ch == 224 || ch == 0) {
            ch = _getch();
            switch (ch) {
            case 72: return UP_ARR;
            case 75: return LEFT_ARR;
            case 77: return RIGHT_ARR;
            case 80: return DOWN_ARR;
            }
        }
    }

    return NONE; 
}