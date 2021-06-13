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

tet_event_list_t *tet_init_event_list(int size);
void tet_destory_event_list(tet_event_list_t *list);
tet_event_t* tet_get_a_slot_from_event_list(tet_event_list_t *list);
void tet_print_event_list(tet_event_list_t *list);

#endif
