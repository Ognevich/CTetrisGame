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