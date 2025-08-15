#include "GameOverControler.h"

void GameOverMessage(int currentScore)
{
    system("cls");
    printf("\n\n\n\n");
    printf(MENU_LINE);
    printf("GAME OVER\n");
    printf("Your Score: %d\n", currentScore);
    printf(MENU_LINE);

    printf("All Score: \n");
    int size = 0;
    int* arr = getAllDataFromFile(&size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    
    clearIntArr(&arr);

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
