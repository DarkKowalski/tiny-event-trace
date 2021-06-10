#ifndef _TINY_EVENT_TRACE_SERIALIZE_H_
#define _TINY_EVENT_TRACE_SERIALIZE_H_

#include <stdio.h>

#include "event.h"
#include "event_list.h"
#include "limit.h"

int tet_serialize_event(char *buffer, int offset, tet_event_t *event);
void tet_serialize_event_list(tet_event_list_t *list);

#endif
