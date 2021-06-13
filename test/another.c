#include "another.h"
#include <unistd.h>

void function3(void)
{
	tet_event_id_t id = tet_global_event_id++;
	tet_trace_begin_default(id);
	sleep(1);
	tet_trace_end_default(id);
}
