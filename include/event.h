#ifndef _TINY_EVENT_TRACE_EVENT_H_
#define _TINY_EVENT_TRACE_EVENT_H_

#include <stdio.h>
#include <time.h>

#include "limit.h"

typedef enum tet_event_phase
{
    PHASE_BEGIN,
    PHASE_END,
    // NOTICE: We only support begin and end phase for now
} tet_event_phase_t;

typedef struct tet_event
{
    char              file[MAX_EVENT_FILE_NAME];
    char              function[MAX_EVENT_FUNCTION_NAME];
    pid_t             pid;
    pid_t             tid;
    tet_event_phase_t phase;
    long            timestamp;
} tet_event_t;

#define TET_DEFAULT_FILE_NAME     __FILE__
#define TET_DEFAULT_FUNCTION_NAME __func__

void tet_print_event(tet_event_t *event)
{
    printf(
        "file: %s\nfunction: %s\npid: %d\ntid: %d\nphase: %d\ntimestamp: %ld\n",
        event->file, event->function, event->pid, event->tid, event->phase,
        event->timestamp);
}

#endif