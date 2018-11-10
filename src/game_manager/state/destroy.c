#include <stdlib.h>

#include "game_state.h"

void gs_destroy(struct game_state *gs)
{
    SDL_DestroyWindow(gs->window);
    free(gs);
}