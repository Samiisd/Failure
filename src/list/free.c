#include <stdlib.h>

#include "list.h"

void list_free(struct list *v)
{
    list_reset(v);
    free(v->data);
    free(v);
}
