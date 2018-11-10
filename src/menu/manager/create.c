#include "menu.h"

static void init_game_window(SDL_Window *window)
{
    // Getting informations of the sreen
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Creating the game window (in full screen)
    window = SDL_CreateWindow(
        "SUPER SAMI !",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        DM.w,
        DM.h,
        SDL_WINDOW_OPENGL
        );

    if (!window)
        errx(1, "Could not create window: %s\n", SDL_GetError());
}

struct menu_manager *menu_manager_create(void)
{
    struct menu_manager *mm = malloc(sizeof(struct menu_manager));
    assert(mm);

    init_game_window(mm->window);
    mm->cur_menu = MAIN_MENU;

    return mm;
}