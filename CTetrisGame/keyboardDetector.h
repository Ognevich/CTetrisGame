#ifndef KEYBOARD_DETECTOR_H
#define KEYBOARD_DETECTOR_H
#include <conio.h>
#include "Config.h"
#include "Utills.h"

typedef enum { LEFT_ARR, RIGHT_ARR, UP_ARR, DOWN_ARR, NONE}keyPressed;

keyPressed keyDetection();


#endif 
