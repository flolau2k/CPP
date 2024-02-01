#include "time.h"

size_t	get_microseconds(void)
{
	size_t		ret;
	t_timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	ret = curr_time.tv_sec * (1000000) + curr_time.tv_usec;
	return (ret);
}
