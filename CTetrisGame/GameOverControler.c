#include "GameOverControler.h"

void GameOverMessage(int currentScore)
{
    system("cls");
    printf("\n\n\n\n");
    printf(MENU_LINE);
    printf("GAME OVER\n");
    printf("Your Score: %d\n", currentScore);
    printf(MENU_LINE);
    printf("\nPress ENTER to exit...");

    while (1) {
        int ch = _getch();
        if (ch == 13) { 
            break;
        }
    }
}

int isGameOver(GameState* state)
{
    int minCoordY = findMinArraYCoord(state->FilledObjectArr);
    if (minCoordY == 0) {
        return 1;
    }
    return 0;
}

void gameOverHandler(GameState* state, GameStateType* gameStateType)
{
    Sleep(1000);
    if (state->isPlaySound)
        playGameOverEffect(&state->sound);
    GameOverMessage(state->gameScore);
    *gameStateType = GAME_MENU;
    saveScoreToFile(state->gameScore);
}
