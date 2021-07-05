#include "../include/event.h"

void tet_print_event(tet_event_t *event)
{
    printf("id: %d\n"
           "file: %s\n"
           "line: %d\n"
           "function: %s\n"
           "pid: %d\n"
           "tid: %d\n"
           "phase: %d\n"
           "timestamp: %ld\n",
           event->id, event->file, event->line, event->function, event->pid,
           event->tid, event->phase, event->timestamp);
}
