#include <stdio.h>
#include <time.h>
#include "GameControler.h"


int main() {
	srand(time(NULL));

	GameState game;

	Init(&game);
	Run(&game);
	shutdown_app(&game);

	return 0;
}