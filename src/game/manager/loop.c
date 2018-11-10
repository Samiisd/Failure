#include "game.h"

#include "person/person.h"

static void handle_user_actions(struct game_manager *gm,
                                SDL_Event *event,
                                struct person *chr)
{
    if (event->key.keysym.sym == SDLK_ESCAPE)
        gm->state = G_PAUSE;
    else if (event->key.keysym.sym == SDLK_RIGHT)
        add_speed(chr->physics, 1, 0);
    else if (event->key.keysym.sym == SDLK_LEFT)
        add_speed(chr->physics, -1, 0);
    else if (event->key.keysym.sym == SDLK_UP)
        add_speed(chr->physics, 0, 1);
}

void game_loop(struct game_manager *gm, SDL_Window *window)
{
    SDL_Event event;

    if (!game_is_init(gm))
        game_init(gm, window, "./res/maps/ground.frc");

    display_map(window, gm->map);

    struct person *main_char = create_person(10, 3);
    spawn_person(window, gm->map, main_char);

    SDL_UpdateWindowSurface(window);

    while (gm->state == G_RUNNING)
    {
	    while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gm->state = G_QUIT;
            else if (event.type == SDL_KEYDOWN)
            {
                SDL_Log("[IN_GAME] Key pressed : %d\n", event.key.keysym.sym);
                handle_user_actions(gm, &event, main_char);
            }
        }

        physics_update(main_char->physics, 0.1);
    }
}