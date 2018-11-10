#include <SDL.h>
#include "game.h"

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window;

    window = SDL_CreateWindow(
        "NAMEOFTHEGAME",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL

        );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 153, 255, 204, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(1000);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}
