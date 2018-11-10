#include "animation.h"

struct clip
{
    int SHEET_WIDTH;
    int SHEET_HEIGHT;
    int nb_of_sprite;

    //Les surfaces
    SDL_Surface *faces; //Ns permet de charger et de manipuler notre feuille de sprites.
    SDL_Surface *screen;

    //Les différentes parties de la feuille de sprites qui vont être blittés
    SDL_Rect left[nb_of_sprite]; // qui va garder les pos et les dim de chacun des sprites
    SDL_Rect right[nb_of_sprite];
};

/*  initialisation de la struct clip */
struct clip *init_clip(enum perso perso_type)
{
    struct clip *clip = calloc(1, sizeof(struct clip));
    if (!clip)
    {
        warnx("struct clip not initialized in init!");
    }

    if (perso_type == HERO)
    {
        clip->SHEET_WIDTH = 200;
        clip->SHEET_HEIGHT = 200;
        clip->nb_of_sprite = 3;
        set_clips(clip);
    }

    if (perso_type == BAD)
    {
        clip->SHEET_WIDTH = 200;
        clip->SHEET_HEIGHT = 200;
        clip->nb_of_sprite = 3;
        set_clips(clip);
    }

    if (perso_type == CLOUD)
    {
        clip->SHEET_WIDTH = 200;
        clip->SHEET_HEIGHT = 200;
        clip->nb_of_sprite = 3;
        set_clips(clip);
    }
    return clip;
}

/*  Decoupage de la feuille de sprites  */
void set_clips(struct clip *clip)
{
    if (!clip)
    {
        warnx("struct clip not initialized in set!");
    }

    for(int i = 0; i < nb_of_sprite; i++)
    {
        clip->right[i].x = clip->SHEET_WIDTH * i;
        clip->right[i].y = 0;
        clip->right[i].w = clip->SHEET_WIDTH;
        clip->right[i].h = clip->SHEET_HEIGHT;
    }

    for(int i = 0; i < nb_of_sprite; i++)
    {
        clip->left[i].x = clip->SHEET_WIDTH * i;
        clip->left[i].y = clip->SHEET_HEIGHT;
        clip->left[i].w = clip->SHEET_WIDTH;
        clip->left[i].h = clip->SHEET_HEIGHT;
    }
}

