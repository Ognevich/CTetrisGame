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
		handleGameStart(state, gameStateType);
		break;
	case GAME_STATISTIC:
		handleGameStatistic(gameStateType);
		break;
	case GAME_SETTINGS:
		handleGameSettings(gameStateType);
		break;
	case GAME_MENU:
		handleGameMenu(gameStateType);
		break;
	case GAME_EXIT:
		break;
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

void handleGameMenu(GameStateType* gameStateType)
{
	int menuOption = 0;
	menuOption = keyMenuDetection(mainMenuArr, MAIN_MENU_SIZE, tetrisGameIntro);
	*gameStateType = convertIntToGameStateType(&menuOption);
}

void handleGameStart(GameState* state, GameStateType* gameStateType)
{
	Init(state);
	RunGame(state, gameStateType);
	shutdown_app(state);
}

void handleGameStatistic(GameStateType* gameStateType)
{
	showScoreStatistic();
	*gameStateType = GAME_MENU;
}
