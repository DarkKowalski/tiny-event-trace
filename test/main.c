#include <tiny_event_trace/tiny_event_trace.h>
#include <tiny_event_trace/global_event_list.h>

#include "another.h"

void function0(void)
{
    tet_event_id_t id = tet_global_event_id++;
    tet_trace_begin_default(id);
    sleep(1);
    tet_trace_end_default(id);
}

void function1(void)
{
    tet_event_id_t id = tet_global_event_id++;
    tet_trace_begin_default(id);
    sleep(1);
    tet_trace_end_default(id);
}

void function2(void)
{
    tet_event_id_t id = tet_global_event_id++;
    tet_trace_begin_default(id);
    sleep(1);
    tet_trace_end_default(id);
}

int main(void)
{
    tet_global_event_list = tet_init_event_list(0);
    tet_global_event_id = 0;

    tet_event_id_t id = tet_global_event_id++;
    tet_trace_begin_default(id);
    function0();
    function0();
    function0();
    function1();
    function2();
    function3();
    tet_trace_end_default(id);

    tet_serialize_event_list(tet_global_event_list);

    tet_destory_event_list(tet_global_event_list);

    return 0;
}
