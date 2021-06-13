#include "../include/trace.h"

void tet_trace(char *file, const char *func, int line, tet_event_id_t id,
               const tet_event_phase_t phase)
{
    tet_event_list_t *list = tet_global_event_list;
    tet_event_t *     event = tet_get_a_slot_from_event_list(list);

    event->file = (char *)file;
    event->function = (char *)func;
    event->line = line;
    event->id = id;

    event->phase = phase;

    event->pid = getpid();
    event->tid = gettid();

    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    time_t ms = t.tv_sec * 1000 + t.tv_nsec / 1E6;
    event->timestamp = ms;
}
