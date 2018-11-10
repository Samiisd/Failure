#include <stdlib.h>
#include <err.h>
#include "physics.h"

void physics_update(struct physic_info *info, double dt)
{
    info->position->y += -0.5 * GRAVITY * dt * dt + info->speed->y * dt;
    info->speed->y += -GRAVITY * dt;
    info->position->x += info->speed->x;
    info->speed->x = 0;
}

void add_speed(struct physic_info *info, struct vector *vect)
{
    info->speed->y += vect->y;
    info->speed->x += vect->x;
}

struct physic_info *init_physics(void)
{
    struct physic_info *physic = calloc(sizeof(struct physic_info), 1);
    if (!physic)
        err(1, "failed calloc physic_info");
    struct vector *position = calloc(sizeof(struct vector),1);
    if (!position)
        err(1, "failed calloc position");
    struct vector *speed = calloc(sizeof(struct vector),1);
    if (!speed)
        err(1, "failed calloc speed");
    physic->position = position;
    physic->speed = speed;
    return physic;
}
