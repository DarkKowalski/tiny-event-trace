#ifndef _TINY_EVENT_TRACE_TRACE_H_
#define _TINY_EVENT_TRACE_TRACE_H_

#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>

#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "event.h"
#include "event_list.h"

extern tet_event_list_t *tet_global_event_list;

void tet_trace(const char *file, const char *func,
               const tet_event_phase_t phase)
{
    tet_event_list_t *list = tet_global_event_list;
    tet_event_t *     event = tet_get_a_slot_from_event_list(list);

    strcpy(event->file, file);
    strcpy(event->function, func);

    event->phase = phase;

    event->pid = getpid();
    event->tid = gettid();

    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    time_t ms = t.tv_sec * 1000 + t.tv_nsec / 1E6;
    event->timestamp = ms;
}

#define tet_trace_begin(file, func) tet_trace(file, func, PHASE_BEGIN)
#define tet_trace_end(file, func)   tet_trace(file, func, PHASE_END)

#define tet_trace_begin_default()                                              \
    tet_trace_begin(TET_DEFAULT_FILE_NAME, TET_DEFAULT_FUNCTION_NAME)
#define tet_trace_end_default()                                                \
    tet_trace_end(TET_DEFAULT_FILE_NAME, TET_DEFAULT_FUNCTION_NAME)

#endif
