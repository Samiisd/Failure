#include "animation.h"

/*  Decoupage de la feuille de sprites  */
static void set_clips(struct clip *clip)
{
    if (!clip)
    {
        warnx("struct clip not initialized in set!");
    }

    clip->left = calloc(clip->nb_of_sprite, sizeof(SDL_Rect));
    clip->right = calloc(clip->nb_of_sprite, sizeof(SDL_Rect));
    if (!clip->left || !clip->right)
    {
        warnx("struct clip left or right not initialized in set!");
    }


    for(int i = 0; i < clip->nb_of_sprite; i++)
    {
        clip->right[i].x = clip->SHEET_WIDTH * i;
        clip->right[i].y = 0;
        clip->right[i].w = clip->SHEET_WIDTH;
        clip->right[i].h = clip->SHEET_HEIGHT;
    }

    for(int i = 0; i < clip->nb_of_sprite; i++)
    {
        clip->left[i].x = clip->SHEET_WIDTH * i;
        clip->left[i].y = clip->SHEET_HEIGHT;
        clip->left[i].w = clip->SHEET_WIDTH;
        clip->left[i].h = clip->SHEET_HEIGHT;
    }
}

static inline void hero_init(struct clip *clip, char *path)
{
    clip->SHEET_WIDTH = 200;
    clip->SHEET_HEIGHT = 200;
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    clip->faces = SDL_LoadBMP(path);
    set_clips(clip);
}

static inline void vilain_init(struct clip *clip, char *path)
{
    clip->SHEET_WIDTH = 200;
    clip->SHEET_HEIGHT = 200;
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    clip->faces = SDL_LoadBMP(path);
    set_clips(clip);
}

static inline void cloud_init(struct clip *clip, char *path)
{
    clip->SHEET_WIDTH = 200;
    clip->SHEET_HEIGHT = 200;
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    clip->faces = SDL_LoadBMP(path);
    set_clips(clip);
}

/*  initialisation de la struct clip */
struct clip *init_clip(enum perso_type perso_type, char *path)
{
    struct clip *clip = calloc(1, sizeof(struct clip));
    if (!clip)
    {
        warnx("struct clip not initialized in init!");
    }

    if (perso_type == HERO)
    {
        hero_init(clip, path);
    }

    if (perso_type == VILAIN)
    {
        vilain_init(clip, path);
    }

    if (perso_type == CLOUD)
    {
        cloud_init(clip, path);
    }
    return clip;
}

/*  Change le mouvement du block  */
void update_anim(struct clip *clip, SDL_Surface *perso_move, enum state cur)
{
    SDL_Rect offset;
    if (cur == LEFT)
    {
        offset.x = clip->left[clip->frame].x;
        offset.y = clip->left[clip->frame].y;
        clip->frame++;
    }
    if (cur == RIGHT)
    {
        offset.x = clip->left[clip->frame].x;
        offset.y = clip->left[clip->frame].y;
        clip->frame++;
    }
    if (clip->frame >= clip->nb_of_sprite)
    {
        clip->frame = 0;
    }

    SDL_BlitSurface(clip->faces, &offset, perso_move, NULL); // &frame &positionperso
}
