#include <stdlib.h>

#include "menu.h"
#include "map/map.h"

#define MAIN_MENU_PATH_BACKGROUND "res/maps/background.frc"

static void render_background(struct menu_manager *mm)
{
    struct map *background = create_map(MAIN_MENU_PATH_BACKGROUND);

    display_map(mm->renderer, background);

    free(background->tilde);
    SDL_FreeSurface(background->surface);
    free(background);
}

void render_menu_main(struct menu_manager *mm)
{
    int winH;
    int winW;
    SDL_GetWindowSize(mm->window, &winW, &winH);

    render_background(mm);
    render_text(mm, "-- Warrior 1.0 --", winW / 2 - 265, 20);
    render_text(mm, "- Press P to play", 30, 200);
    render_text(mm, "- Press E to exit", 30, 260);
}
