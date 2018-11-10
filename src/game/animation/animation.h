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
    RIGHT
};

struct clip
{
    int SHEET_WIDTH;
    int SHEET_HEIGHT;
    int nb_of_sprite;
    int frame;
    SDL_Surface *faces;
    SDL_Surface *move_cur;
    SDL_Rect *left;
    SDL_Rect *right;
};

struct clip *init_clip(enum perso_type perso_type, char *path);
void update_anim(struct clip *clip, enum state cur);

#endif /* ! ANIMATION_H */
