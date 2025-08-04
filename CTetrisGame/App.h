#define _CRT_SECURE_NO_WARNINGS
#ifndef APP_H
#define APP_H
#include "stdio.h"
#include "MapControler.h"
#include "keyboardDetector.h"
#include <windows.h>

void Run();
void Init();
void Update();
void shutdown_app();

void playerActionHandler();

#endif
