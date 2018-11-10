#ifndef PERSON_H
#define PERSON_H

#include "physic/physics.h"
#include "map/map.h"
#include <SDL.h>

struct person
{
    struct physic_info *physics;
    float health;
    SDL_Rect rect;
    SDL_Surface *surface;
};

struct person *create_person(int x, int y);
void spawn_person(SDL_Renderer *renderer, struct map *map, struct person *person);

#endif /* ! PERSON_H */
