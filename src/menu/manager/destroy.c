#include "menu.h"

void menu_manager_destroy(struct menu_manager *mm)
{
    SDL_DestroyWindow(mm->window);
    free(mm);
}