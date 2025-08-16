#include "SoundSystem.h"

void initAudio()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 0;
    }
}
