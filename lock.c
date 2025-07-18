#include <reg51.h>
#include "lock.h"
sbit LOCK = P1^3;
void lock_init(void) 
{
    LOCK = 0;
}
void lock_open(void) 
{
    LOCK = 1;
}
void lock_close(void)
 {
    LOCK = 0;
}