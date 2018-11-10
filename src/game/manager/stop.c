#include "game.h"

void game_stop(struct game_manager *gm)
{
    gm->window = NULL;
    gm->persons = NULL;
    gm->state = G_INIT;
    list_free(gm->persons);
}