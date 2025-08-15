#define _CRT_SECURE_NO_WARNINGS
#ifndef FILE_CONTROLER_H
#define FILE_CONTROLER_H
#include <stdio.h>
#include "FilePath.h"
#include "Utills.h"

void saveScoreToFile(int scoreToSave);
int* getAllDataFromFile(int * outSize);
int* readTopFiveScores();


#endif
