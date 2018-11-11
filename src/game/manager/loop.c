#define _XOPEN_SOURCE
#include <stdlib.h>

#include "game.h"

#include "menu.h"
#include "animation/animation.h"
#include "person/person.h"

static void handle_user_actions(struct game_manager *gm, SDL_Event *event)
{
    struct person *main_character = game_get_player(gm);

    if (event->key.keysym.sym == SDLK_ESCAPE)
        gm->state = G_PAUSE;
    else if (event->key.keysym.sym == SDLK_SPACE)
        jump(main_character->physics);
}

static inline int is_between(double x, double a, double b)
{
    return x >= a && x < b;
}

static int persons_collide(struct person *pers_1, struct person *pers_2)
{
    if (is_between(16 * pers_1->physics->position->x, 16 * pers_2->physics->position->x, 16 * pers_2->physics->position->x + 64)
    || is_between(16 * pers_1->physics->position->x + 64, 16 * pers_2->physics->position->x, 16 * pers_2->physics->position->x + 64))
    {
        int res = pers_1->physics->position->y < 8;
        if (res)
            SDL_Log("Colliding");
        return res;
    }

    return 0;
}

static void update_persons_physics(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    struct person *main_character = list_at(gm->persons, 0);

    for (size_t i = 0; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        if (cur->physics->position->y != -1 && cur->physics->position->x != -1)
        {
            if (i > 0 && cur->physics->speed->x == 0.0)
                defile(cur->physics);
            physics_update(cur->physics, gm->map);

            if (i > 0 && persons_collide(main_character, cur))
                gm->state = G_QUIT;
        }
    }
}

static void display_persons(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    for (size_t i = 0; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        if (cur->physics->position->y != -1 &&
            (cur->physics->position->x != -1 || drand48() < 0.005))
            spawn_person(gm->renderer, gm->map, cur);
    }
}

static void pop_random_enemies(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    for (size_t i = 1; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        if (cur->physics->position->y == -1 && cur->physics->position->x == -1
            && drand48() < 0.008)
        {
           cur->physics->position->x = 115;
           cur->physics->position->y = 56;
        }
    }
}

void game_loop(struct menu_manager *mm, struct game_manager *gm)
{
    SDL_Event event;
    struct person *main_character = game_get_player(gm);
    Uint32 last_tick = SDL_GetTicks();
    char score_str [100];

    int winH;
    int winW;
    SDL_GetWindowSize(mm->window, &winW, &winH);

    if (gm->state == G_PAUSE)
    {
        /* RESTORE GAME STATE ...*/
        gm->state = G_RUNNING;
    }
    else
    {
        gm->score = 0;
    }

    SDL_RenderClear(gm->renderer);

    while (gm->state == G_RUNNING)
    {

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gm->state = G_QUIT;
            else if (event.type == SDL_KEYDOWN)
            {
                SDL_Log("[IN_GAME] Key pressed : %d\n", event.key.keysym.sym);
                handle_user_actions(gm, &event);
            }
        }

        Uint32 current_tick = SDL_GetTicks();
        sprintf(score_str, "%d", ++(gm->score));
        if (current_tick > last_tick + 70)
        {
            anim_update(main_character->clip, RUN);
            last_tick = current_tick;
        }

        pop_random_enemies(gm);

        SDL_RenderClear(gm->renderer);
        update_persons_physics(gm);
        display_map(gm->renderer, gm->map);
        render_text(mm, score_str, 20, 20);
        display_persons(gm);
        SDL_RenderPresent(gm->renderer);
    }
}
