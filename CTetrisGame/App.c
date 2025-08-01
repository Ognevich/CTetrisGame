#include "App.h"

void Run()
{

	while (1) {
	
		createMap();
		showMap();
		wait();
	}


}

void Init()
{
	initMapArray();
}

void shutdown_app() {
	freeMapArray();
}
