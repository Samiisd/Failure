#include "list.h"

void *list_pop(struct list *v)
{
    if (!list_size(v))
        return NULL;

    return v->data[--(v->index)];
}
