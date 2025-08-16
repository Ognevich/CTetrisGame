#include "Score.h"

int getScore(GameState* state)
{
	return state->gameScore;
}

void increaseScore(GameState* state, int new_score) {
	state->gameScore += new_score;
}

void showScoreStatistic()
{
	system("cls");

	printf("The Highest Score: \n");
	int* arr = readTopFiveScores();
	for (int i = 0; i < 5; i++) {
		printf("    %d. -- %d\n",i+1, arr[i]);
	}
	printf("\nPress ENTER to exit...");

	while (1) {
		int ch = _getch();
		if (ch == 13) {
			break;
		}
	}

	clearIntArr(&arr);

}
