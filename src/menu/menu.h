#pragma once

#include <SDL.h>
#include <err.h>
#include <assert.h>

enum menu_type
{
    MAIN_MENU,
    MENU_GAME,
    MENU_OPTIONS,
    MENU_EXIT,

    NB_MENU_TYPE
};

struct menu_manager
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    enum menu_type cur_menu;
};

struct menu_manager *menu_manager_create(void);
void menu_manager_loop(struct menu_manager *mm);
void menu_manager_destroy(struct menu_manager *mm);