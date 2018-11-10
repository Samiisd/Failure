#include <stdlib.h>

#include "list.h"

static int list_resize(struct list *v, int capacity)
{

    void **new_data = realloc(v->data, sizeof(void *) * capacity);
    if (!new_data)
        return 0;

    v->data = new_data;
    v->capacity = capacity;

    return 1;
}

int list_push(struct list *v, void *item)
{
    if (v->index == v->capacity && !list_resize(v, v->capacity * 2))
        return 0;

    v->data[v->index++] = item;
    return 1;
}
