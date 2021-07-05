#include "../include/event_list.h"

tet_event_list_t *tet_init_event_list(int size)
{
    if (size > MAX_EVENT)
    {
        fprintf(stderr,
                "Failed to initialize Event List. Given size: %d Max size: "
                "%d. Abort!\n",
                size, MAX_EVENT);
        exit(1);
    }

    int events = size <= 0 ? MAX_EVENT : size;

    tet_event_list_t *list =
        (tet_event_list_t *)malloc(sizeof(tet_event_list_t));
    tet_event_t *slot = (tet_event_t *)malloc(sizeof(tet_event_t) * events);
    if (list == NULL || slot == NULL)
    {
        fprintf(stderr, "Failed to initialize Event List. Abort!\n");
        exit(1);
    }

    list->slot = slot;
    list->pointer = 0;
    return list;
}

void tet_destroy_event_list(tet_event_list_t *list)
{
    if (list == NULL || list->slot == NULL)
    {
        fprintf(stderr, "Failed to destroy Event List. Abort!\n");
        exit(1);
    }

    free(list->slot);
    free(list);
}

tet_event_t *tet_get_a_slot_from_event_list(tet_event_list_t *list)
{

    if (list->pointer > MAX_EVENT - 1 || list->pointer < 0)
    {
        fprintf(stderr,
                "Failed to get a slot from Event List. pointer = %d . Abort!\n",
                list->pointer);
        exit(1);
    }

    int          pointer = list->pointer++;
    tet_event_t *slot = &(list->slot[pointer]);

    slot->file = NULL;
    slot->function = NULL;

    return slot;
}

void tet_print_event_list(tet_event_list_t *list)
{
    int pointer = list->pointer;
    for (int i = 0; i < pointer; i++)
    {
        printf("index: %d\n", i);
        tet_print_event(&(list->slot[i]));
    }
}
