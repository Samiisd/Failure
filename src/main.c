#include <SDL.h>
#include "menu.h"

int main(void)
{
    // Game initialization
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    struct menu_manager *mm = menu_manager_create();

    // Menu loop
    menu_manager_loop(mm);

    // Releasing game ressources
    menu_manager_destroy(mm);
    SDL_Quit();

    return 0;
}