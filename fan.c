#include <reg51.h>
#include "fan.h"
sbit FAN = P1^0;
void fan_init(void)
 {
    FAN = 0;
}
void fan_on(void)
 {
    FAN = 1;
}
void fan_off(void)
 {
    FAN = 0;
}
