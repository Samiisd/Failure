#include "list.h"

void list_reset(struct list *v)
{
    if (v->free_fnct)
    {
        for (size_t i = 0; i < list_size(v); i++)
            v->free_fnct(v->data[i]);
    }

    v->index = 0;
}
