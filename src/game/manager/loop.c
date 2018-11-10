#include "game.h"

#include "person/person.h"

static void handle_user_actions(struct game_manager *gm, SDL_Event *event)
{
    struct person *main_character = game_get_player(gm);

    if (event->key.keysym.sym == SDLK_ESCAPE)
        gm->state = G_PAUSE;
    else if (event->key.keysym.sym == SDLK_RIGHT)
        add_speed(main_character->physics, 1, 0);
    else if (event->key.keysym.sym == SDLK_LEFT)
        add_speed(main_character->physics, -1, 0);
    else if (event->key.keysym.sym == SDLK_UP)
        add_speed(main_character->physics, 0, 1);
}

static void update_persons_physics(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    for (size_t i = 0; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        physics_update(cur->physics, 0.001);
    }
}

static void display_persons(struct game_manager *gm)
{
    size_t nb_persons = list_size(gm->persons);
    for (size_t i = 0; i < nb_persons; i++)
    {
        struct person *cur = list_at(gm->persons, i);
        spawn_person(gm->renderer, gm->map, cur);
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

    display_map(gm->renderer, gm->map);
    display_persons(gm);

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

        update_persons_physics(gm);

        SDL_RenderPresent(gm->renderer);
        SDL_Delay(100);
    }
}