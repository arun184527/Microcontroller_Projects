#include <reg51.h>
sbit LED = P1^0;
void delay() {
    int i, j;
    for(i=0; i<1000; i++)
        for(j=0; j<1275; j++);
}
void main() {
    while(1) {
        LED = 1;  
        delay();
        LED = 0; 
        delay();
    }
}