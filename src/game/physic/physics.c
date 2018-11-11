#include <stdlib.h>
#include <err.h>
#include "physics.h"

void physics_update(struct physic_info *info, struct map *map, double dt)
{
    dt +=1;
    info->position->y += info->speed->y/2;// -0.5 * GRAVITY * dt *10 + info->speed->y * dt;
    info->speed->y -= 0.07;
    info->position->x += info->speed->x/2;
    info->speed->x /= 1.2;
    if (info->speed->x)
    if (info->position->y - 1 < 0
        || get_block_type(map, info->position->x, info->position->y - 1)
        || get_block_type(map, info->position->x, info->position->y - 1))
        info->speed->y = 0;

}

void add_speed(struct physic_info *info, double x, double y)
{
    if (y && info->speed->y)
        return;

    info->speed->y += y;
    info->speed->x += x;

    if (info->speed->x > 1)
        info->speed->x = 1;
    if (info->speed->y > 1)
        info->speed->y = 1;
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
