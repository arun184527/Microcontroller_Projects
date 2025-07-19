#include <reg51.h>
unsigned char numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                             0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void delay()
 {
    int i, j;
    for(i=0; i<500; i++)
        for(j=0; j<1275; j++);
}

void main() 
{
    int i;
    while(1) 
{
        for(i = 0; i < 10; i++) 
{
            P2 = numbers[i];
            delay();
        }
    }
}