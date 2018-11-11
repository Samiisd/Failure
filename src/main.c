#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "menu.h"

int main(void)
{
    // Game initialization
    if (TTF_Init() != 0)
    {
        SDL_Log("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    struct menu_manager *mm = menu_manager_create();

    // Menu loop
    menu_manager_loop(mm);

    // Releasing game ressources
    menu_manager_destroy(mm);
    TTF_Quit();
    SDL_Quit();

    return 0;
}