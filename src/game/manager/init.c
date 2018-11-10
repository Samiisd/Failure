#include "person/person.h"
#include "game.h"

static void delete_person_list(void *p_)
{
    struct person *p = p_;
    destroy_person(p);
}

void game_init(struct game_manager *gm, SDL_Renderer *renderer, char *map_path)
{
    gm->renderer = renderer;
    gm->state = G_RUNNING;

    gm->persons = list_init(GAME_INIT_DEFAULT_NB_PLAYER, delete_person_list);
    gm->map = create_map(map_path);
}