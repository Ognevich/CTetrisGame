#ifndef CONFIG_H
#define CONFIG_H
#include <stdio.h>
//FULL MAP
#define MAP_HEIGHT 20
#define MAP_WIDTH 27
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
#define FAST_FALL_DELAY 50
#define MOVE_DELAY 40

#endif
