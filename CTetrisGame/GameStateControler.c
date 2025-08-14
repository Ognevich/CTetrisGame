#include "GameStateControler.h"

void runProgram(GameStateType* gameStateType, GameState * state)
{

	while (*gameStateType != GAME_EXIT) {
		handleCurrentGameState(gameStateType, state);
	}
}

void handleCurrentGameState(GameStateType * gameStateType, GameState* state)
{
	int menuOption = 0;
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
		handleGameSettings(gameStateType);
		break;
	case GAME_EXIT:
		break;
	case GAME_MENU:
		menuOption = keyMenuDetection(mainMenuArr, MAIN_MENU_SIZE, tetrisGameIntro);
		*gameStateType = convertIntToGameStateType(&menuOption);
	default:
		break;
	}
}

void handleGameSettings(GameStateType* gameStateType)
{
	int settingsMenuOption = 0;
	settingsMenuOption = keyMenuDetection(settingsMenuArr, SETTINGS_MENU_SIZE, settingsIntro);
	chooseGameColor(settingsMenuOption);
	*gameStateType = GAME_MENU;
	return;
}
