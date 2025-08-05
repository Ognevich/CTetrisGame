#include "Figures.h"


const char figureI[OBJECT_SIZE][OBJECT_SIZE] = {
    {'0', ' ', ' '},
    {'0', ' ', ' '},
    {'0', ' ', ' '}
};

const char figureO[OBJECT_SIZE][OBJECT_SIZE] = {
    {'0', '0', ' '},
    {'0', '0', ' '},
    {' ', ' ', ' '}
};

const char figureS[OBJECT_SIZE][OBJECT_SIZE] = {
    {' ', '0', '0'},
    {'0', '0', ' '},
    {' ', ' ', ' '}
};

const char figureZ[OBJECT_SIZE][OBJECT_SIZE] = {
    {'0', '0', ' '},
    {' ', '0', '0'},
    {' ', ' ', ' '}
};

const char figureL[OBJECT_SIZE][OBJECT_SIZE] = {
    {'0', ' ', ' '},
    {'0', ' ', ' '},
    {'0', '0', ' '}
};

const char figureJ[OBJECT_SIZE][OBJECT_SIZE] = {
    {' ', ' ', '0'},
    {' ', ' ', '0'},
    {' ', '0', '0'}
};

const char figureT[OBJECT_SIZE][OBJECT_SIZE] = {
    {'0', '0', '0'},
    {' ', '0', ' '},
    {' ', ' ', ' '}
};


const char (*figures_arr[7])[OBJECT_SIZE] = {
    figureI, figureO, figureS, figureZ, figureL, figureJ, figureT
};
