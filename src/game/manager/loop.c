#include "game.h"

void game_loop(struct game_manager *gm, SDL_Window *window)
{
    SDL_Event event;

    if (!game_is_init(gm))
        game_init(gm, window, "res/maps/ground.frc");

    display_map(window, gm->map);
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
            }
        }
    }
}