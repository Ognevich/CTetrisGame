#include "MenuArr.h"

const char* mainMenuArr[MAIN_MENU_SIZE] = {
    "Start Game",
    "Statistic",
    "Settings",
    "Exit",
};

const char* settingsMenuArr[SETTINGS_MENU_SIZE] = {
    "Blue Neon",
    "Retro Terminal",
    "Pop Arcade",
    "Futuristic",
    "Default"
};

void tetrisGameIntro()
{
    printf("=================\n");
    printf("   TETRIS GAME   \n");
    printf("=================\n");
}

void settingsIntro()
{
    printf("=================\n");
    printf("     SETTINGS    \n");
    printf("=================\n");
}