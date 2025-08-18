#ifndef SOUND_SYSTEM_H
#define SOUND_SYSTEM_H
#include <stdio.h>
#include <SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2/SDL_main.h>
#include <Windows.h>
#include "Config.h"

typedef struct {

	Mix_Chunk* rotateEffect;
	Mix_Chunk* CollisionEffect;
	Mix_Chunk* clearLineEffect;
	Mix_Chunk* gameOverEffect;
	Mix_Chunk* gameStartEffect;

}SoundSystem;

void initAudio(SoundSystem * sound);
void playRotateEffect(SoundSystem* sound);
void playObjectCollisionEffect(SoundSystem* sound);
void playClearLineEffect(SoundSystem* sound);
void playGameOverEffect(SoundSystem* sound);
void playGameStartEffect(SoundSystem * sound);

void shutdownAudio(SoundSystem* sounds);


#endif
