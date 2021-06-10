#ifndef _TINY_EVENT_TRACE_LIMIT_H_
#define _TINY_EVENT_TRACE_LIMIT_H_

#include <stdint.h>

#define MAX_EVENT (8192)

#define SERIALIZE_EVENT_BUFFER      (256)
#define SERIALIZE_EVENT_LIST_BUFFER (SERIALIZE_EVENT_BUFFER * MAX_EVENT + 64)

#endif
