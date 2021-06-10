#include "../include/event.h"

void tet_print_event(tet_event_t *event)
{
    printf(
        "file: %s\nfunction: %s\npid: %d\ntid: %d\nphase: %d\ntimestamp: %ld\n",
        event->file, event->function, event->pid, event->tid, event->phase,
        event->timestamp);
}
