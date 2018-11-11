#include "animation/animation.h"
#include "list.h"
#include <stdio.h>

static void set_clips(struct clip *clip, int cur)
{
    if (!clip)
    {
        warnx("struct clip not initialized in set!");
    }
    clip->run = list_init(clip->nb_of_sprite, NULL);
    if (!clip->run)
    {
        warnx("struct clip left or right not initialized in set!");
    }

    if (cur == 1)
    {
        list_push(clip->run, SDL_LoadBMP("./res/anim/run0.bmp"));
        list_push(clip->run, SDL_LoadBMP("./res/anim/run2.bmp"));
        list_push(clip->run, SDL_LoadBMP("./res/anim/run3.bmp"));
    }
    if (cur == 3)
    {
        list_push(clip->run, SDL_LoadBMP("./res/maps/img/b.bmp"));
    }

}

static inline void hero_init(struct clip *clip, int cur)
{
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    set_clips(clip, cur);
}

static inline void vilain_init(struct clip *clip, int cur)
{
    clip->nb_of_sprite = 1;
    clip->frame = 0;
    set_clips(clip, cur);
}

static inline void cactus_init(struct clip *clip, int cur)
{
    clip->nb_of_sprite = 1;
    clip->frame = 0;
    set_clips(clip, cur);
}


struct clip *init_clip(int perso_type)
{
    struct clip *clip = calloc(1, sizeof(struct clip));
    if (!clip)
    {
        warnx("struct clip not initialized in init!");
        return NULL;
    }

    if (perso_type == 1)
    {
        hero_init(clip, perso_type);
    }

    if (perso_type == 2)
    {
        vilain_init(clip, perso_type);
    }

    if (perso_type == 3)
    {
        cactus_init(clip, perso_type);
    }

    return clip;
}

void anim_init(struct clip *clip)
{
    clip->move_cur = list_at(clip->run, 0);
    clip->frame++;
}

void anim_update(struct clip *clip, enum state cur)
{
    if (cur == RUN)
    {
        clip->move_cur = list_at(clip->run, clip->frame);
        clip->frame++;
    }

    if (cur == DEAD)
    {
        clip->move_cur = list_at(clip->run, clip->frame);
        clip->frame++;
    }

    if (clip->frame >= clip->nb_of_sprite)
    {
        clip->frame = 0;
    }
}
