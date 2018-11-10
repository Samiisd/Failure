#include "game.h"

void game_init(struct game_manager *gm, SDL_Window *window)
{
    gm->window = window;
    gm->state = G_RUNNING;

    /* Should add map_load etc... */
}