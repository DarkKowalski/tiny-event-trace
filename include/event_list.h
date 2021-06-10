#ifndef _TINY_EVENT_TRACE_EVENT_LIST_H_
#define _TINY_EVENT_TRACE_EVENT_LIST_H_

#include "event.h"
#include "limit.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct tet_event_list
{
    int          pointer;
    tet_event_t *slot;
} tet_event_list_t;

tet_event_list_t *tet_init_event_list(void)
{
    tet_event_list_t *list =
        (tet_event_list_t *)malloc(sizeof(tet_event_list_t));
    tet_event_t *slot = (tet_event_t *)malloc(sizeof(tet_event_t) * MAX_EVENT);
    if (list == NULL || slot == NULL)
    {
        fprintf(stderr, "Failed to initialize Event List. Abort!\n");
        exit(1);
    }

    list->slot = slot;
    return list;
}

void tet_destory_event_list(tet_event_list_t *list)
{
    if (list == NULL || list->slot == NULL)
    {
        fprintf(stderr, "Failed to destory Event List. Abort!\n");
        exit(1);
    }

    free(list->slot);
    free(list);
}

tet_event_t* tet_get_a_slot_from_event_list(tet_event_list_t *list)
{

    if (list->pointer > MAX_EVENT - 1 || list->pointer < 0)
    {
        fprintf(stderr,
                "Failed to get a slot from Event List. pointer = %d . Abort!\n",
                list->pointer);
        exit(1);
    }

    int          pointer = list->pointer++;
    tet_event_t *slot = &(list->slot[pointer]);

    return slot;
}

void tet_print_event_list(tet_event_list_t *list)
{
    int pointer = list->pointer;
    for (int i = 0; i < pointer; i++)
    {
        printf("index: %d\n", i);
        tet_print_event(&(list->slot[i]));
    }
}

#endif
