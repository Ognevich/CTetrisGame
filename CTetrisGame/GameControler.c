#include "GameControler.h"

static DWORD lastMoveTime = 0;
static DWORD lastFallTime = 0;
static DWORD lastRotateTime = 0;
static DWORD lastMoveSideTime = 0;

void RunGame(GameState* state, GameStateType* gameStateType)
{
    while (*gameStateType == GAME_START) {
        Update(state, gameStateType);
        Sleep(1); 
    }
}

void Init(GameState* state)
{
    InitGameState(state);
    if (state->isPlaySound) {
        initAudio(&state->sound);
        playGameStartEffect(&state->sound);
    }
    resetObject(state);
}

void Update(GameState* state, GameStateType* gameStateType)
{
    DWORD now = GetTickCount64();

    if (now - lastMoveTime >= MOVE_DELAY) {
        playerActionHandler(state,gameStateType);
        lastMoveTime = now;
    }

    DWORD fallDelay = state->isFastFalling ? FAST_FALL_DELAY : NORMAL_FALL_DELAY;

    if (now - lastFallTime >= fallDelay) {
        int arrSize = 0;
        Vector2* coordVector = findAllArrayObjects(state->tempFigureArr, &arrSize);
        int isCanFall = checkGroundCollision(state, coordVector, &arrSize);
        if (isCanFall == 1) {
            moveObjectDown(state);
        }
        else {
            handleStopObject(state, gameStateType, coordVector);
        }
        lastFallTime = now;
    }

    updateMap(state);
    showMap(state);
    clearGameScreen();
}

void shutdown_app(GameState* state) {
    clearGameState(state);
    shutdownAudio(&state->sound);
}

void playerActionHandler(GameState* state, GameStateType* gameStateType)
{
    keyPressed keyValue = keyDetection();
    DWORD now = GetTickCount64();

    switch (keyValue)
    {
    case LEFT_ARR:
        if (now - lastMoveSideTime >= SIDE_MOVE_DELAY) {
            handleLeftMovement(state);
            lastMoveSideTime = now;
        }
        break;

    case RIGHT_ARR:
        if (now - lastMoveSideTime >= SIDE_MOVE_DELAY) {
            handleRightMovement(state);
            lastMoveSideTime = now;
        }
        break;

    case UP_ARR:
        if (now - lastRotateTime >= ROTATE_DELAY) {
            rotateObject(state);
            lastRotateTime = now;
        }
        break;

    case DOWN_ARR:
        speedUpObject(state);
        break;
    case ESC_BTN:
        gameOverHandler(state, gameStateType);
        *gameStateType = GAME_MENU;
        break;
    case NONE:
        resetFallSpeed(state);
        break;

    default:
        break;
    }
}

void handleLeftMovement(GameState* state)
{
    if (checkLeftWallCollision(state) == 0) {
        if (checkLeftObjectCollision(state) == 0) {
            moveObjectLeft(state);
        }
    }
}

void handleRightMovement(GameState* state)
{
    if (checkRightWallCollision(state) == 0) {
        if (checkRightObjectCollision(state) == 0) {
            moveObjectRight(state);
        }
    }

}

void SaveGameStatus(GameState* state, GameStateType* gameStateType)
{
    Sleep(500);
    addValuesToFilledObjectArr(state);
    ClearFullLine(state);
    if (isGameOver(state)) {
        gameOverHandler(state, gameStateType);
        return;
    }
    increaseScore(state, DEFAULT_SCORE_INCRESE);
    resetObject(state);
}

void handleStopObject(GameState* state, GameStateType* gameStateType, Vector2* coordVector)
{
    clearVector2Arr(&coordVector);
    if (state->isPlaySound)
        playObjectCollisionEffect(&state->sound);
    SaveGameStatus(state, gameStateType);
}
