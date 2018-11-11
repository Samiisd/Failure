#include "game.h"

#include "animation/animation.h"
#include "person/person.h"

static void handle_user_actions(struct game_manager *gm, SDL_Event *event)
{
    struct person *main_character = game_get_player(gm);

    if (event->key.keysym.sym == SDLK_ESCAPE)
        gm->state = G_PAUSE;
    else if (event->key.keysym.sym == SDLK_SPACE)
    {
        anim_update(main_character->clip, IDLE);
        jump(main_character->physics);
    }
}

static void update_persons_physics(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);

    for (size_t i = 0; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        if (cur->physics->y == -1 || cur->physics->x == -1)
        {
            if (cur->physics->speed->x == 0)
                defile(cur->physics);
            physics_update(cur->physics, gm->map);
        }
    }
}

static void display_persons(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    for (size_t i = 0; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        if (cur->physics->y != -1 && cur->physics->x != -1)
            spawn_person(gm->renderer, gm->map, cur);
    }
}

static void pop_random_enemies(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    for (size_t i = 1; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        if (cur->physics->y == -1 && cur->physics->x == -1
            && drand48() < 0.01)
        {
            cur->physics->x = 480;
            cur->physics->y = 10;
        }
    }
}

void game_loop(struct game_manager *gm)
{
    SDL_Event event;

    if (gm->state == G_PAUSE)
    {
        /* RESTORE GAME STATE ...*/
        gm->state = G_RUNNING;
    }
    else
    {
        SDL_RenderClear(gm->renderer);
    }

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

        pop_random_enemies(gm);

        SDL_RenderClear(gm->renderer);
        update_persons_physics(gm);
        display_map(gm->renderer, gm->map);
        display_persons(gm);
        SDL_RenderPresent(gm->renderer);
    }
}
