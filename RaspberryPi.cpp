#include "RaspberryPi.h"
#include <time.h>

void delay(unsigned long ms)
{
    struct timespec req, rem;
    req.tv_sec = 0;
    req.tv_nsec = ms * 1000000;

    nanosleep(&req, &rem);
}

unsigned long millis(void)
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return tp.tv_sec*1000 + tp.tv_nsec/1000000;
}
