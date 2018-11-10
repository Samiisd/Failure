#include <err.h>

#include "map.h"
#include "person.h"

struct person *create_person(int x, int y)
{
    struct person *p = calloc(sizeof(struct person), 1);
    if (!p)
        err(1,"failed calloc person");
    p->health = 1;
    p->surface = NULL;
    struct physic_info *phy_inf = init_physics();
    p->physics = phy_inf;

    p->physics->position->x = x;
    p->physics->position->y = y;
    return p;
}

void spawn_person(SDL_Window *window, struct map *map, struct person *person)
{
    SDL_Surface* sprite = SDL_LoadBMP("./src/maps/img/blk.bmp");
    window = window;
    int x = person->physics->position->x;
    int y = person->physics->position->y;
    if (sprite)
    {
        SDL_Rect src = {158, 209, 16, 16};
        if (get_block_type(map, x, y) != BLOCK)
        {
            SDL_Rect dest = {x*16, (map->height-y)*16, 16, 16};
            SDL_BlitSurface(sprite, &src, SDL_GetWindowSurface(window),
                            &dest);

        }
    }
    else
    {
        err(1, "failed loading sprite (%s)",SDL_GetError());
    }
}
