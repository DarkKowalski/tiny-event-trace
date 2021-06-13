#ifndef _TINY_EVENT_TRACE_TRACE_H_
#define _TINY_EVENT_TRACE_TRACE_H_

#include "limit.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sys/types.h>
#include <unistd.h>

#include <sys/time.h>
#include <time.h>

#include "event.h"
#include "event_list.h"

extern tet_event_list_t *tet_global_event_list;

void tet_trace(char *file, const char *func,
               int line, const tet_event_phase_t phase);

#define tet_trace_begin(file, func, line) tet_trace(file, func, line, PHASE_BEGIN)
#define tet_trace_end(file, func, line) tet_trace(file, func, line, PHASE_END)

#define tet_trace_begin_default() \
    tet_trace_begin(TET_DEFAULT_FILE_NAME, TET_DEFAULT_FUNCTION_NAME, TET_DEFAULT_LINE_NUMBER)
#define tet_trace_end_default() \
    tet_trace_end(TET_DEFAULT_FILE_NAME, TET_DEFAULT_FUNCTION_NAME, TET_DEFAULT_LINE_NUMBER)

#endif
