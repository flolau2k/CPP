#ifndef TIME_H
#define TIME_H

#include <sys/time.h>
#include <unistd.h>

typedef struct timeval t_timeval;

size_t	get_microseconds(void);

#endif // TIME_H
