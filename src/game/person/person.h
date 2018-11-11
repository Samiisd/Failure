#ifndef PERSON_H
#define PERSON_H

#include "physic/physics.h"
#include "map/map.h"
#include <SDL.h>

struct person
{
    struct physic_info *physics;
    float health;
    struct clip *clip;
    SDL_Surface *surface;
};

struct person *create_person(int x, int y);
void spawn_person(SDL_Renderer *renderer, struct map *map, struct person *person);
void destroy_person(struct person *person);

#endif /* ! PERSON_H */
