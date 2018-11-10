#pragma once

#include <SDL.h>
#include <stdbool.h>

#include "person/person.h"
#include "map/map.h"
#include "menu.h"
#include "list.h"

#define GAME_INIT_DEFAULT_NB_PLAYER 2

enum game_state
{
    G_INIT,

    G_PAUSE,
    G_RUNNING,

    G_QUIT
};

struct game_manager
{
    SDL_Renderer *renderer;
    struct map *map;
    struct list *persons;
    enum game_state state;
};

static inline bool game_is_init(struct game_manager *gm)
{
    return gm && gm->window && gm->state != G_INIT;
}

static inline struct person *game_get_player(struct game_manager *gm)
{
    return list_at(gm->persons, 0);
}

void game_init(struct game_manager *gm, SDL_Renderer *renderer, char *map_path);
void game_loop(struct game_manager *gm);
void game_stop(struct game_manager *gm);
