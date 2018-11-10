#include "menu.h"
#include "game.h"

static void menu_init_game(struct menu_manager *mm, struct game_manager *gm)
{
    game_init(gm, mm->renderer, "./res/maps/ground.frc");
    list_push(gm->persons, create_person(10, 3));

}

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

                if (!game_is_init(&gm))
                    menu_init_game(mm, &gm);

                game_loop(&gm);

                if (gm.state == G_PAUSE)
                    mm->cur_menu = MENU_OPTIONS;
                else if (gm.state == G_QUIT)
                {
                    game_stop(&gm);
                    mm->cur_menu = MENU_EXIT;
                }
            }
        }
    }

}
