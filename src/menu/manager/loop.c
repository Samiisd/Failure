#include "menu.h"
#include "game.h"

void menu_manager_loop(struct menu_manager *mm)
{
    SDL_Event event;

    struct game_manager gm;
    gm.state = G_INIT;

    while (mm->cur_menu != MENU_EXIT)
    {
	    while (SDL_PollEvent(&event))
        {
			if (event.type == SDL_QUIT)
                mm->cur_menu = MENU_EXIT;

            else if (event.type == SDL_KEYDOWN)
            {
                SDL_Log("[IN_MENU] Key pressed : %d\n", event.key.keysym.sym);
                mm->cur_menu = MENU_GAME;

                game_loop(&gm, mm->window);

                if (gm.state == G_PAUSE)
                    mm->cur_menu = MENU_OPTIONS;
                else if (gm.state == G_QUIT)
                    mm->cur_menu = MENU_EXIT;
            }
        }
    }
}