#ifndef KEYBOARD_DETECTOR_H
#define KEYBOARD_DETECTOR_H
#include <conio.h>
#include "GameStateType.h"
#include "Config.h"
#include "Utills.h"

typedef enum { LEFT_ARR, RIGHT_ARR, UP_ARR, DOWN_ARR, NONE}keyPressed;

keyPressed keyDetection();
int keyMenuDetection(const char** menuType, int menuSize, void (*func)(void));
int getPressKey(int *menuOption, int menuSize);


#endif 
