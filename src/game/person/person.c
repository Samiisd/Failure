#include <err.h>

#include "animation/animation.h"
#include "map/map.h"
#include "person/person.h"

struct person *create_person(int x, int y)
{
    struct person *p = calloc(sizeof(struct person), 1);
    if (!p)
        err(1,"failed calloc person");
    p->health = 1;
    p->surface = SDL_LoadBMP("./res/maps/img/blk.bmp");
    struct physic_info *phy_inf = init_physics();
    p->physics = phy_inf;
    p->physics->position->x = x;
    p->physics->position->y = y;
    p->clip = init_clip(HERO);
    anim_init(p->clip);
    return p;
}

void spawn_person(SDL_Renderer *renderer, struct map *map, struct person *person)
{
    float x = person->physics->position->x;
    float y = person->physics->position->y;

    SDL_Surface* sprite = person->clip->move_cur;
    if (!sprite)
        err(1, "sprite load failed");

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,sprite);
    if (!texture)
        err(1, "texture texture");
    SDL_Rect dest = {x*16, (map->height-y)*16, 96, 96};

    SDL_Rect src = {158, 209, 16, 16};
    SDL_Rect dest = {x*16, (map->height-y)*16, 16, 16};

    SDL_RenderCopy(renderer,texture,&src,&dest);

    SDL_RenderPresent(renderer);
}
