#include "App.h"

static DWORD lastMoveTime = 0;
static DWORD lastFallTime = 0;

void Run()
{
    Init();

    while (1) {
        Update();
        Sleep(1); 
    }

    shutdown_app();
}

void Init()
{
    initMapArray();
    setDafaultCoordPos();
    moveVectorPos();
    createMap();
}

void Update()
{
    DWORD now = GetTickCount64();

    if (now - lastMoveTime >= 40) {
        playerActionHandler();
        lastMoveTime = now;
    }

    if (now - lastFallTime >= 400) {
        moveObjectDown();
        lastFallTime = now;
    }

    updateMap();
    showMap();
    clearGameScreen();
}

void shutdown_app() {
    freeMapArray();
}

void playerActionHandler()
{
    keyPressed keyValue = keyDetection();

    switch (keyValue)
    {
    case LEFT_ARR:
        moveObjectLeft();
        break;
    case RIGHT_ARR:
        moveObjectRight();
        break;
    case UP_ARR:
        break;
    case DOWN_ARR:
        break;
    case NONE:
        break;
    default:
        break;
    }
}
