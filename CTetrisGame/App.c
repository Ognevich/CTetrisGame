#include "App.h"

void Run()
{

	while (1) {
	
		Update();
		wait();
	}


}

void Init()
{
	initMapArray();
	setDafaultCoordPos();
	MoveVectorPos();
	createMap();
}

void Update()
{
	updateMap();
	moveObject();
	showMap();
}

void shutdown_app() {
	freeMapArray();
}
