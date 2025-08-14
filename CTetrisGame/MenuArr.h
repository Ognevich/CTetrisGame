#ifndef MENU_ARR_H
#define MENU_ARR_H
#include <stdio.h>
#include "Config.h"

extern const char* mainMenuArr[MAIN_MENU_SIZE];
extern const char* settingsMenuArr[SETTINGS_MENU_SIZE];

void tetrisGameIntro();
void settingsIntro();
#endif
