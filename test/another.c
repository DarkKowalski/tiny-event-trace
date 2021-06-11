#include "another.h"
#include <unistd.h>

void function3(void)
{
	tet_trace_begin_default();
	sleep(1);
	tet_trace_end_default();
}
