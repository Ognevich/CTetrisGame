#include "App.h"

static DWORD lastMoveTime = 0;
static DWORD lastFallTime = 0;

void Run(GameState* state)
{
    while (1) {
        Update(state);
        Sleep(1); 
    }
}

void Init(GameState* state)
{
    InitGameState(state);
    resetObject(state);
}

void Update(GameState* state)
{
    DWORD now = GetTickCount64();

    if (now - lastMoveTime >= 40) {
        playerActionHandler(state);
        lastMoveTime = now;
    }

    if (now - lastFallTime >= 400) {
        int value = checkGroundCollision(state);
        if (value == 0) {
            moveObjectDown(state);
        }
        else {
            Sleep(500);
            addValuesToFilledObjectArr(state);
            resetObject(state);
        }
        
        lastFallTime = now;
    }

    updateMap(state);
    showMap(state);
    clearGameScreen();
}

void shutdown_app(GameState* state) {
    clearGameState(state);
}

void playerActionHandler(GameState* state)
{
    keyPressed keyValue = keyDetection();

    switch (keyValue)
    {
    case LEFT_ARR:
        handleLeftMovement(state);
        break;
    case RIGHT_ARR:
        handleRightMovement(state);
        break;
    case UP_ARR:
        rotateObject(state);
        break;
    case DOWN_ARR:
        break;
    case NONE:
        break;
    default:
        break;
    }
}

void handleLeftMovement(GameState* state)
{
    int isLeftCollision = checkLeftWallCollision(state);
    if (isLeftCollision == 0) {
        moveObjectLeft(state);
    }
}

void handleRightMovement(GameState* state)
{
    int isRightCollision = checkRightWallCollision(state);

    if (isRightCollision== 0) {
        moveObjectRight(state);
    }

}
