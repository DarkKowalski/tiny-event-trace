#include "../include/serialize.h"

char tet_event_phase_str[2] = {'B', 'E'};

int tet_serialize_event(char *buffer, int offset, tet_event_t *event)
{
    char *buf = buffer + offset;

    return sprintf(buf,
                   "{\"name\": \"%s:%s\",\n"
                   "\"ph\":\"%c\",\n"
                   "\"pid\":\"%i\",\n"
                   "\"tid\":\"%i\",\n"
                   "\"ts\":\"%ld\"},\n",
                   event->file, event->function,
                   tet_event_phase_str[event->phase], event->pid, event->tid,
                   event->timestamp);
}

void tet_serialize_event_list(tet_event_list_t *list)
{
    char *buffer = (char*)malloc(sizeof(char) * SERIALIZE_EVENT_LIST_BUFFER);
    if (buffer == NULL)
    {
        fprintf(
            stderr,
            "Failed to allocated buffer for serialization process. Abort!\n");
        exit(1);
    }

    int offset = sprintf(buffer, "[\n");
    int pointer = list->pointer;
    for (int i = 0; i < pointer; i++)
    {
        offset += tet_serialize_event(buffer, offset, &(list->slot[i]));
    }
    offset += sprintf(buffer + offset - 2, "\n]\n"); /* Remove the last `,` */

    FILE *stream = fopen("tiny_event_trace.json", "w");
    if (stream == NULL)
    {
        fprintf(stderr, "Failed to write file. Abort!\n");
        exit(1);
    }
    fputs(buffer, stream);

    fclose(stream);
    free(buffer);
}
