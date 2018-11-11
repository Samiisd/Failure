#include "menu.h"

void menu_manager_destroy(struct menu_manager *mm)
{
    SDL_DestroyWindow(mm->window);
    SDL_DestroyRenderer(mm->renderer);
    TTF_CloseFont(mm->text_font);
    free(mm);
}