#include "animation/animation.h"
#include "list.h"
#include <stdio.h>

/*  Decoupage de la feuille de sprites  */
static void set_clips(struct clip *clip)
{
    if (!clip)
    {
        warnx("struct clip not initialized in set!");
    }

    clip->idle = list_init(4, NULL);
    clip->left = list_init(4, NULL);
    clip->right = list_init(4, NULL);
    //clip->left = calloc(clip->nb_of_sprite, sizeof(SDL_Rect));
    //clip->right = calloc(clip->nb_of_sprite, sizeof(SDL_Rect));
    if (!clip->left || !clip->right)
    {
        warnx("struct clip left or right not initialized in set!");
    }

    list_push(clip->idle, SDL_LoadBMP("./res/anim/idle0.bmp"));
    list_push(clip->idle, SDL_LoadBMP("./res/anim/idle1.bmp"));
    list_push(clip->idle, SDL_LoadBMP("./res/anim/idle2.bmp"));
    list_push(clip->idle, SDL_LoadBMP("./res/anim/idle3.bmp"));

    list_push(clip->left, SDL_LoadBMP("./res/anim/right0.bmp"));
    list_push(clip->left, SDL_LoadBMP("./res/anim/right1.bmp"));
    list_push(clip->left, SDL_LoadBMP("./res/anim/right2.bmp"));
    list_push(clip->left, SDL_LoadBMP("./res/anim/right3.bmp"));

    list_push(clip->right, SDL_LoadBMP("./res/anim/left0.bmp"));
    list_push(clip->right, SDL_LoadBMP("./res/anim/left1.bmp"));
    list_push(clip->right, SDL_LoadBMP("./res/anim/left2.bmp"));
    list_push(clip->right, SDL_LoadBMP("./res/anim/left3.bmp"));
}

static inline void hero_init(struct clip *clip)
{
    clip->SHEET_WIDTH = 200;
    clip->SHEET_HEIGHT = 200;
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    set_clips(clip);
}

static inline void vilain_init(struct clip *clip)
{
    clip->SHEET_WIDTH = 200;
    clip->SHEET_HEIGHT = 200;
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    set_clips(clip);
}

static inline void cloud_init(struct clip *clip)
{
    clip->SHEET_WIDTH = 200;
    clip->SHEET_HEIGHT = 200;
    clip->nb_of_sprite = 3;
    clip->frame = 0;
    set_clips(clip);
}

/*  initialisation de la struct clip */
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

    if (perso_type == CLOUD)
    {
        cloud_init(clip);
    }
    printf("Done\n");
    return clip;
}

/*  Creation du premier block perso  */
void anim_init(struct clip *clip)
{
    //clip->move_cur = NULL;
    //clip->move_cur = SDL_CreateRGBSurface (0, clip->SHEET_WIDTH, clip->SHEET_HEIGHT, 32, 0, 0, 0, 0);
    clip->move_cur = list_at(clip->idle, 0);
    clip->frame++;
}

/*  Change le mouvement du block  */
void anim_update(struct clip *clip, enum state cur)
{
    if (cur == LEFT)
    {
        clip->move_cur = list_at(clip->left, clip->frame);
        //clip->move_cur = clip->left[clip->frame];
        clip->frame++;
    }
    if (cur == RIGHT)
    {
        clip->move_cur = list_at(clip->right, clip->frame);
        //clip->move_cur = clip->left[clip->frame];
        clip->frame++;
    }
    if (cur == IDLE)
    {
        clip->move_cur = list_at(clip->right, clip->frame);
        //clip->move_cur = clip->idle[clip->frame];
        clip->frame++;
    }

    if (clip->frame >= clip->nb_of_sprite)
    {
        clip->frame = 0;
    }
    //printf("frame: %d move; %d\n", clip->frame, cur);
    //SDL_BlitSurface(clip->faces, &offset, clip->move_cur, NULL); // &frame &positionperso
}
