#ifndef _TINY_EVENT_TRACE_H_
#define _TINY_EVENT_TRACE_H_

#include "limit.h"
#include "event.h"
#include "event_list.h"
#include "trace.h"
#include "serialize.h"

/* Need to include global_event_list for the first time */
extern tet_event_list_t *tet_global_event_list;
extern tet_event_id_t    tet_global_event_id;

#endif
