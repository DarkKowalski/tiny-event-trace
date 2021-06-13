#ifndef _TINY_EVENT_TRACE_GLOBAL_LIST_H_
#define _TINY_EVENT_TRACE_GLOBAL_LIST_H_

#include "event_list.h"

/* Notice: once include once */

__attribute__((visibility("default"))) tet_event_list_t *tet_global_event_list;
__attribute__((visibility("default"))) tet_event_id_t    tet_global_event_id;

#endif
