#include "game.h"

void game_stop(struct game_manager *gm)
{
    gm->renderer = NULL;
    gm->state = G_INIT;
    list_free(gm->persons);
    gm->persons = NULL;
}