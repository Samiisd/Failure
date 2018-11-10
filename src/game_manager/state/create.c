#include <stdlib.h>
#include <err.h>

#include "game_state.h"

static void init_game_window(SDL_Window *window)
{
    // Getting informations of the sreen
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Creating the game window (in full screen)
    window = SDL_CreateWindow(
        "NAMEOFTHEGAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        DM.w,
        DM.h,
        SDL_WINDOW_OPENGL
        );

    if (!window)
        errx(1, "Could not create window: %s\n", SDL_GetError());
}

struct game_state *gs_create(void)
{
    struct game_state *gs = malloc(sizeof(struct game_state));

    init_game_window(gs->window);

    return gs;
}