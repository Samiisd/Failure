#include "animation/animation.h"
#include "list.h"
#include <stdio.h>

static void set_clips(struct clip *clip)
{
    if (!clip)
    {
        warnx("struct clip not initialized in set!");
    }

    clip->run = list_init(5, NULL);
    if (!clip->run)
    {
        warnx("struct clip left or right not initialized in set!");
    }

    list_push(clip->run, SDL_LoadBMP("./res/anim/run0.bmp"));
    //list_push(clip->run, SDL_LoadBMP("./res/anim/run1.bmp"));
    list_push(clip->run, SDL_LoadBMP("./res/anim/run2.bmp"));
    list_push(clip->run, SDL_LoadBMP("./res/anim/run3.bmp"));
    //list_push(clip->run, SDL_LoadBMP("./res/anim/run4.bmp"));
}

static inline void hero_init(struct clip *clip)
{
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    set_clips(clip);
}

static inline void vilain_init(struct clip *clip)
{
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    set_clips(clip);
}


struct clip *init_clip(enum perso_type perso_type)
{
    struct clip *clip = calloc(1, sizeof(struct clip));
    if (!clip)
    {
        warnx("struct clip not initialized in init!");
        return NULL;
    }

    if (perso_type == HERO)
    {
        hero_init(clip);
    }

    if (perso_type == VILAIN)
    {
        vilain_init(clip);
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
