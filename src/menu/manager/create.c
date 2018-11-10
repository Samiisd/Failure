#include "menu.h"

static void init_game_window(struct menu_manager *mm)
{
    // Getting informations of the sreen
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Creating the game window (in full screen)
    mm->window = SDL_CreateWindow(
        "SUPER SAMI !",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
        );

    if (!mm->window)
        errx(1, "Could not create window: %s\n", SDL_GetError());
}

struct menu_manager *menu_manager_create(void)
{
    struct menu_manager *mm = malloc(sizeof(struct menu_manager));
    assert(mm);

    init_game_window(mm);
    mm->cur_menu = MAIN_MENU;

    return mm;
}