#include "SoundSystem.h"


void initAudio(SoundSystem* sounds)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        DBG("SDL_Init Error: %s\n", SDL_GetError());
        return 0;
    }

    if (Mix_OpenAudio(4410, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        DBG("SDL_Init Error: %s\n", SDL_GetError());
    }

    sounds->rotateEffect = Mix_LoadWAV("sounds/rotateSound.wav");
    if (!sounds->rotateEffect) printf("Failed to load rotateSound.wav: %s\n", Mix_GetError());

    sounds->CollisionEffect = Mix_LoadWAV("sounds/landingSound.wav");
    if (!sounds->CollisionEffect) printf("Failed to load rotateSound.wav: %s\n", Mix_GetError());

    sounds->clearLineEffect = Mix_LoadWAV("sounds/clearLineSound.wav");
    if (!sounds->clearLineEffect) printf("Failed to load rotateSound.wav: %s\n", Mix_GetError());

}

void playRotateEffect(SoundSystem* sounds)
{
    if (sounds->rotateEffect)
        Mix_PlayChannel(-1, sounds->rotateEffect, 0);
}

void playObjectCollisionEffect(SoundSystem* sounds)
{
    if (sounds->CollisionEffect)
        Mix_PlayChannel(-1, sounds->CollisionEffect, 0);
}

void playClearLineEffect(SoundSystem* sounds)
{
    if (sounds->clearLineEffect)
        Mix_PlayChannel(-1, sounds->clearLineEffect, 0);
}

void shutdownAudio(SoundSystem* sounds)
{
    if (sounds->rotateEffect) Mix_FreeChunk(sounds->rotateEffect);
    if (sounds->CollisionEffect) Mix_FreeChunk(sounds->CollisionEffect);
    if (sounds->clearLineEffect) Mix_FreeChunk(sounds->clearLineEffect);

    Mix_CloseAudio();
    SDL_Quit();
}
