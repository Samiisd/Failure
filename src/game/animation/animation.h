#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include <err.h>

enum perso_type
{
    HERO,
    VILAIN,
    CLOUD
};

enum state
{
    LEFT,
    RIGHT,
    IDLE
};

struct clip
{
    int SHEET_WIDTH;
    int SHEET_HEIGHT;
    int nb_of_sprite;
    int frame;
    struct list *idle;
    struct list *left;
    struct list *right;
   SDL_Surface *move_cur;
};

struct clip *init_clip(enum perso_type perso_type);
void anim_update(struct clip *clip, enum state cur);
void anim_init(struct clip *clip);

#endif /* ! ANIMATION_H */
