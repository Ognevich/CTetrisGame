#include <stdio.h>
#include <time.h>
#include "App.h"


int main() {
	srand(time(NULL));

	Init();
	Run();
	shutdown_app();

	return 0;
}