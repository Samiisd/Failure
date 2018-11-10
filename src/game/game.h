#pragma once

#include <SDL/SDL.h>
#include <stdbool.h>

#include "menu.h"

enum game_state
{
    G_INIT,

    G_PAUSE,
    G_RUNNING,

    G_QUIT
};

struct game_manager
{
    SDL_Window *window;
    enum game_state state;
};

static inline bool game_is_init(struct game_manager *gm)
{
    return gm && gm->window && gm->state != G_INIT;
}

void game_init(struct game_manager *gm, SDL_Window *window);
void game_loop(struct game_manager *gm, SDL_Window *window);
void game_stop(struct game_manager *gm);