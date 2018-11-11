#include <stdlib.h>
#include <err.h>
#include "physics.h"


void jump(struct physic_info *inf)
{
    if (inf->position->y < 7)
        inf->speed->y = 3;
}

void defile(struct physic_info *inf)
{
    add_speed(inf, 0.45, 0);
}


static int collision(struct map *map, struct physic_info *info)
{
    return get_block_type(map, info->position->x,
                          info->position->y) == BLOCK
        || get_block_type(map, info->position->x,
                          info->position->y - 1) == BLOCK
        || get_block_type(map, info->position->x,
                          info->position->y - 2) == BLOCK
        || get_block_type(map, info->position->x,
                          info->position->y - 3) == BLOCK
        || get_block_type(map, info->position->x,
                          info->position->y - 4) == BLOCK;

}

void physics_update(struct physic_info *info, struct map *map)
{
    if (collision(map, info) && info->speed->y < 0)
        info->speed->y = 0;
    else
    {

        info->position->y += info->speed->y / 2;
        if (info->speed->y < -0.8)
            info->speed->y = -0.8;
        info->speed->y -= 0.2;
    }

    info->position->x -= info->speed->x;

    if (info->position->x < 0)
    {
        info->speed->x = 0;
        info->position->x = -1;
        info->position->y = -1;
    }
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
