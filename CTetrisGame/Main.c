#include <stdio.h>
#include <time.h>
#include "App.h"


int main() {
	srand(time(NULL));

	GameState game;

	Init(&game);
	Run(&game);
	shutdown_app(&game);

	return 0;
}