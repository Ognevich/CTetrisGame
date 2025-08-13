#include "GameStateControler.h"

void runProgram(GameStateType* gameStateType, GameState * state)
{

	while (*gameStateType != GAME_EXIT) {
		handleCurrentGameState(gameStateType, state);
	}
}

void handleCurrentGameState(GameStateType * gameStateType, GameState* state)
{

	switch (*gameStateType)
	{
	case GAME_START:

		Init(state);
		RunGame(state);
		shutdown_app(state);

		break;
	case GAME_STATISTIC:
		*gameStateType = GAME_MENU;
		break;
	case GAME_SETTINGS:
		*gameStateType = GAME_MENU;
		break;
	case GAME_EXIT:
		break;
	case GAME_MENU:
		keyMenuDetection(gameStateType);
	default:
		break;
	}
}
