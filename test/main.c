#include <tiny_event_trace/tiny_event_trace.h>
#include <tiny_event_trace/global_event_list.h>

#include "another.h"

void function0(void)
{
    tet_trace_begin_default();
    sleep(1);
    tet_trace_end_default();
}

void function1(void)
{
    tet_trace_begin_default();
    sleep(1);
    tet_trace_end_default();
}

void function2(void)
{
    tet_trace_begin_default();
    sleep(1);
    tet_trace_end_default();
}

int main(void)
{
    tet_global_event_list = tet_init_event_list(0);

    tet_trace_begin_default();
    function0();
    function1();
    function2();
    function3();
    tet_trace_end_default();

    tet_serialize_event_list(tet_global_event_list);

    tet_destory_event_list(tet_global_event_list);

    return 0;
}
