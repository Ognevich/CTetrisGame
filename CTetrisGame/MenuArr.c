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
    printf(MENU_LINE);
    printf("   TETRIS GAME   \n");
    printf(MENU_LINE);
}

void settingsIntro()
{
    printf(MENU_LINE);
    printf("     SETTINGS    \n");
    printf(MENU_LINE);
}