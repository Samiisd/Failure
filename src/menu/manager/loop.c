#include "menu.h"
#include "game.h"

static void menu_init_game(struct menu_manager *mm, struct game_manager *gm)
{
    game_init(gm, mm->renderer, "./res/maps/ground.frc");
    list_push(gm->persons, create_person(10, 8));
}

static void handle_user_actions(struct menu_manager *mm, SDL_Event *event)
{
    SDL_Log("[IN_MENU] Key pressed : %d\n", event->key.keysym.sym);
    if (event->key.keysym.sym == SDLK_e)
        mm->cur_menu = MENU_EXIT;
    else if (event->key.keysym.sym == SDLK_p)
        mm->cur_menu = MENU_GAME;
}

void menu_manager_loop(struct menu_manager *mm)
{
    SDL_Event event;

    struct game_manager gm;
    gm.state = G_INIT;

    render_menu_main(mm);
    SDL_RenderPresent(mm->renderer);

    while (mm->cur_menu != MENU_EXIT)
    {
            while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                mm->cur_menu = MENU_EXIT;

            else if (event.type == SDL_KEYDOWN)
                handle_user_actions(mm, &event);
        }

        if (mm->cur_menu == MENU_GAME)
        {
            if (!game_is_init(&gm))
                menu_init_game(mm, &gm);

            game_loop(&gm);

            if (gm.state == G_PAUSE)
            {
                render_menu_options(mm);
                SDL_RenderPresent(mm->renderer);
                mm->cur_menu = MENU_OPTIONS;
            }
            else if (gm.state == G_QUIT)
            {
                game_stop(&gm);
                mm->cur_menu = MENU_EXIT;
            }
        }

        if (mm->cur_menu == MENU_OPTIONS)
        {
            if (event.key.keysym.sym == SDLK_r)
                mm->cur_menu = MENU_GAME;
            else if (event.key.keysym.sym == SDLK_b
                  || event.key.keysym.sym == SDLK_e)
            {
                game_stop(&gm);

                if (event.key.keysym.sym == SDLK_e)
                    mm->cur_menu =  MENU_EXIT;
                else
                {
                    mm->cur_menu = MENU_MAIN;
                    render_menu_main(mm);
                    SDL_RenderPresent(mm->renderer);
                }
            }
            else if (event.key.keysym.sym == SDLK_r)
                mm->cur_menu = MENU_GAME;
        }
    }

}
