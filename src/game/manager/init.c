#include "game.h"

void game_init(struct game_manager *gm, SDL_Window *window, char *map_path)
{
    gm->window = window;
    gm->state = G_RUNNING;

    gm->map = create_map(map_path);
}