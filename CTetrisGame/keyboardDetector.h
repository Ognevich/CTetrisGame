#ifndef KEYBOARD_DETECTOR_H
#define KEYBOARD_DETECTOR_H
#include <conio.h>
#include "GameStateType.h"
#include "Config.h"
#include "Utills.h"
#include "MenuArr.h"

typedef enum { LEFT_ARR, RIGHT_ARR, UP_ARR, DOWN_ARR, NONE}keyPressed;

keyPressed keyDetection();
void keyMenuDetection(GameStateType * gameStateType);
int getPressKey(int *menuOption, int menuSize);


#endif 
