#include <reg51.h>
#include "light.h"
sbit LIGHT = P1^1;
void light_init(void)
 {
    LIGHT = 0;
}
void light_on(void) 
{
    LIGHT = 1;
}
void light_off(void)
 {
    LIGHT = 0;
}