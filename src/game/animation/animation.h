#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <err.h>

enum perso_type
{
    HERO,
    VILAIN,
    CACTUS
};

enum state
{
    RUN,
    DEAD
};

struct clip
{
    int nb_of_sprite;
    int frame;
    struct list *run;
    struct list *dead;
    SDL_Surface *move_cur;
};

struct clip *init_clip(int perso_type);
void anim_update(struct clip *clip, enum state cur);
void anim_init(struct clip *clip);

#endif /* ! ANIMATION_H */
