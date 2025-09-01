#include "MenuArr.h"

const char* mainMenuArr[MAIN_MENU_SIZE] = {
    "Start Game",
    "Statistic",
    "Settings",
    "Exit",
};

const char* settingsMenuArr[SETTINGS_MENU_SIZE] = {
    "Sound",
    "Colors",
    "Exit",
};

const char* colorSettingsMenuArr[COLOR_SETTINGS_MENU_SIZE] = {
    "Blue Neon",
    "Retro Terminal",
    "Pop Arcade",
    "Futuristic",
    "Midnight Code",    
    "Cyber Aqua",       
    "Royal Blue",
    "Default"
};

const char* soundSettingsMenuArr[SOUND_SETTINGS_MENU_SIZE] = {
    "Turn on",
    "Turn off",
    "Exit",
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

void soundSettingsIntro()
{
    printf(MENU_LINE);
    printf("  SOUND SETTINGS \n");
    printf(MENU_LINE);

}

void colorSettingsIntro()
{
    printf(MENU_LINE);
    printf("  COLOR SETTINGS \n");
    printf(MENU_LINE);

}