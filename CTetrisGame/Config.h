#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
//FULL MAP
#define MAP_HEIGHT 15
#define MAP_WIDTH 17
//OBJECT MAP
#define OBJECT_MAP_HEIGHT ((MAP_HEIGHT-2))
#define OBJECT_MAP_WIDTH ((MAP_WIDTH-2))
//UTILLS
#define SLEEP_TIME 200

//OBJECTS
#define START_POS_X (((MAP_WIDTH-1) / 2))
#define START_POS_Y 1
#define OBJECT_SIZE 3

// DELAY 
#define NORMAL_FALL_DELAY 400
#define FAST_FALL_DELAY 70
#define MOVE_DELAY 60
#define ROTATE_DELAY 300
#define SIDE_MOVE_DELAY 100

// MENU
#define MAIN_MENU_SIZE 4
#define SETTINGS_MENU_SIZE 3
#define COLOR_SETTINGS_MENU_SIZE 8
#define SOUND_SETTINGS_MENU_SIZE 3
#define MENU_LINE "=================\n"


//SCORE 
#define DEFAULT_SCORE_INCRESE 100
#define LINE_CLEAR_SCORE_INCRESE 1000


// DEBUG
//#define NDEBUG

#ifdef NDEBUG
	#define DBG(...) ((void)0)
#else
	#define DBG(...) printf(__VA_ARGS__)
#endif

#endif
