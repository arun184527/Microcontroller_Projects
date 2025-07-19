#include <reg51.h>
sbit LED = P1^0;
void ext0_isr(void) interrupt 0 
{
    LED = ~LED;  // Toggle LED
}

void main() 
{
    IT0 = 1;    // INT0 falling edge trigger
    EX0 = 1;    // Enable INT0
    EA = 1;     // Enable global interrupt
    while(1);   // Wait forever
}