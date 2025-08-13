#include <stdio.h>
#include <time.h>
#include "GameControler.h"
#include "GameStateControler.h"

int main() {
	srand(time(NULL));
	GameState game;
	GameStateType gameState = GAME_MENU;
	runProgram(&gameState, &game);
	return 0;
}