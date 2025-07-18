#include <reg51.h>
#include "buzzer.h"
sbit BUZZER = P1^2;
void buzzer_init(void) 
{
    BUZZER = 0;
}
void buzzer_on(void) 
{
    BUZZER = 1;
}
void buzzer_off(void)
 {
    BUZZER = 0;
}