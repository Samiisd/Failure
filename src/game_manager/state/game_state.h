#pragma once

#include <SDL.h>

struct game_state
{
    SDL_Window *window;
}

struct game_state *gs_create(void);
void gs_destroy(struct game_state *gs);