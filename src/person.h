#ifndef PERSON_H
#define PERSON_H

#include "physics.h"
#include <SDL.h>

struct person
{
    struct physic_info *physics;
    float health;
    SDL_Surface *surface;
};

struct person *create_person(int x, int y);
void spawn_person(SDL_Window *window, struct map *map, struct person *person);

#endif /* ! PERSON_H */
