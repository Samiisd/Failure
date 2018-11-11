#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <err.h>
#include <assert.h>

#include "list.h"

enum menu_type
{
    MENU_MAIN,
    MENU_GAME,
    MENU_OPTIONS,
    MENU_EXIT,

    NB_MENU_TYPE
};

struct menu_manager
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    TTF_Font *text_font;
    enum menu_type cur_menu;
};

struct menu_manager *menu_manager_create(void);
void menu_manager_loop(struct menu_manager *mm);
void menu_manager_destroy(struct menu_manager *mm);

/* Internals */
void render_text(struct menu_manager *mm, const char *txt, int x, int y);
void render_menu_main(struct menu_manager *mm);
void render_menu_options(struct menu_manager *mm);