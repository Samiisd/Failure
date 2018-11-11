#include "menu.h"

static void init_game_window(struct menu_manager *mm)
{
    // Getting informations of the sreen
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    SDL_Window *window = SDL_CreateWindow("Ca compile on se casse !",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          1120, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED
                                                | SDL_RENDERER_PRESENTVSYNC);

    mm->window = window;
    mm->renderer = renderer;

    if (!mm->window)
        errx(1, "Could not create window: %s\n", SDL_GetError());

    if (!mm->renderer)
        errx(1, "Could not create window: %s\n", SDL_GetError());

}

struct menu_manager *menu_manager_create(void)
{
    struct menu_manager *mm = malloc(sizeof(struct menu_manager));
    assert(mm);

    init_game_window(mm);
    mm->text_font = TTF_OpenFont("res/fonts/04B_30__.TTF", 40);
    mm->cur_menu = MENU_MAIN;

    return mm;
}
