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
		handleGameSettings(state,gameStateType);
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

void handleGameSettings(GameState* state,GameStateType* gameStateType)
{
	int settingsMenuOption = 0;
	settingsMenuOption = keyMenuDetection(settingsMenuArr, SETTINGS_MENU_SIZE, settingsIntro);
	chooseGameSetting(state,settingsMenuOption);
	*gameStateType = GAME_MENU;
	return;
}

void chooseGameSetting(GameState* state,int gameSettingsOption)
{
	switch (gameSettingsOption)
	{
	case 0: {
		handleGameSoundSettings(state);
		break;
	}
	case 1:
	{
		handleGameColorSettings();
		break;
	}
	default:
		break;
	}

}

void handleGameColorSettings()
{
	int settingsMenuOption = 0;
	settingsMenuOption = keyMenuDetection(colorSettingsMenuArr, COLOR_SETTINGS_MENU_SIZE, colorSettingsIntro);
	chooseGameColor(settingsMenuOption);
	return;
}

void handleGameSoundSettings(GameState* state)
{
	int settingsMenuOption = 0;
	settingsMenuOption = keyMenuDetection(soundSettingsMenuArr, SOUND_SETTINGS_MENU_SIZE, soundSettingsIntro);
	
	switch (settingsMenuOption)
	{
	case 0:
	{
		state->isPlaySound = 1;
		break;
	}
	case 1: 
	{
		state->isPlaySound = 0;
		break;
	}
	default:
		break;
	}

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
