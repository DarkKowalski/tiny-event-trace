#ifndef _TINY_EVENT_TRACE_EVENT_H_
#define _TINY_EVENT_TRACE_EVENT_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>
#include <time.h>
#include <stdio.h>

#include "limit.h"

typedef enum tet_event_phase
{
    PHASE_BEGIN,
    PHASE_END,
    // NOTICE: We only support begin and end phase for now
} tet_event_phase_t;

typedef struct tet_event
{
    char              *file;
    char              *function;
    pid_t             pid;
    pid_t             tid;
    tet_event_phase_t phase;
    long              timestamp;
} tet_event_t;

#define TET_DEFAULT_FILE_NAME     __FILE__
#define TET_DEFAULT_FUNCTION_NAME __func__

void tet_print_event(tet_event_t *event);

#endif
