#ifndef PHYSICS_H
#define PHYSICS_H

#define GRAVITY 9
struct vector
{
    float x;
    float y;
};
#include "../map/map.h"

struct physic_info
{
    struct vector *speed;
    struct vector *position;
    float mass;
    int collison;
};

void physics_update(struct physic_info *info, struct map *map, double dt);
void add_speed(struct physic_info *info, double x, double y);
struct physic_info *init_physics(void);

#endif /* ! PHYSICS_H */
